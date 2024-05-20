//
// Created by Alex Balta on 18.05.2024.
//

#include "Service.hpp"

std::vector<Song> Service::getAll() {
    std::vector<Song> res = repo.getAll();

    std::sort(res.begin(), res.end(), [](const Song &s1, const Song &s2) {
        return s1.getTitle() < s2.getTitle();
    });

    return res;
}

void Service::addSong(const std::string &title, const std::string &artist, const std::string &genre) {
    if (title.empty() || artist.empty() || genre.empty()) {
        throw ServiceException("You cannot enter a empty string.");
    }
    if (!(genre == "pop" || genre == "rock" || genre == "folk" || genre == "disco")) {
        throw ServiceException("The genre should be pop, rock, folk or disco.");
    }

    int id = generateUniqId();
    Song song(id, title, artist, genre);
    repo.addSong(song);
}

void Service::deleteSong(int id) {
    if (!repo.findSong(id)) {
        throw ServiceException("The song doesn't exist.");
    }

    repo.deleteSong(id);
}

void Service::updateSong(int id, const std::string &title,
                         const std::string &artist, const std::string &genre) {
    if (!repo.findSong(id)) {
        throw ServiceException("The song doesn't exist");
    }
    if (title.empty() || artist.empty() || genre.empty()) {
        throw ServiceException("You cannot enter a empty string.");
    }
    if (!(genre == "pop" || genre == "rock" || genre == "folk" || genre == "disco")) {
        throw ServiceException("The genre should be pop, rock, folk or disco.");
    }

    Song new_song(id, title, artist, genre);
    repo.updateSong(id, new_song);
}

std::map<std::string, int> Service::raportArtist() {
    std::map<std::string, int> res;

    for (const Song &song : repo.getAll()) {
        res[song.getArtist()] += 1;
    }

    return res;
}

std::map<std::string, int> Service::raportGenre() {
    std::map<std::string, int> res;

    for (const Song &song : repo.getAll()) {
        res[song.getGenre()] += 1;
    }

    return res;
}

int Service::generateUniqId() {
    int maxId = 0;
    for (const auto &song : repo.getAll()) {
        if (song.getId() > maxId) {
            maxId = song.getId();
        }
    }
    return maxId + 1;
}
