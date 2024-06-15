//
// Created by Alex Balta on 17.05.2024.
//

#include "Service.hpp"

Service::Service(Repository &repo) : repo{repo} {}

std::vector<Song> Service::getSongs() const {
    std::vector<Song> res{repo.getAll()};

    std::sort(res.begin(), res.end(),
              [&](const Song &s1, const Song &s2) {
                  return s1.getTitle() < s2.getTitle();
              });

    return res;
}

int Service::getLen() const {
    return (int) repo.getAll().size();
}

void Service::deleteSong(int id) {
    if (!repo.findSong(id)) {
        throw ServiceException{"The song was not found."};
    }

    auto items = repo.getAll();
    auto it = std::find_if(items.begin(), items.end(),
                           [id](const Song &s) {
                               return s.getId() == id;
                           });

    if (raportArtists()[it->getAuthor()] == 1) {
        throw ServiceException("Cannot delete the last song of the artist!");
    }

    repo.deleteSong(id);
    notify();
}

void Service::updateSong(int id, const std::string &new_title, int new_rank) {
    if (new_rank > 10 || new_rank < 0 || new_title.empty()) {
        throw ServiceException{"The title or the rank are not valid."};
    }

    repo.updateSong(id, new_title, new_rank);
    notify();
}

std::vector<int> Service::raportRanks() const {
    std::vector<int> res(11, 0);

    for (const Song &song : repo.getAll()) {
        res[song.getRank()] += 1;
    }

    return res;
}

std::unordered_map<std::string, int> Service::raportArtists() {
    std::unordered_map<std::string, int> res;

    for (const Song &song : repo.getAll()) {
        res[song.getAuthor()] += 1;
    }

    return res;
}
