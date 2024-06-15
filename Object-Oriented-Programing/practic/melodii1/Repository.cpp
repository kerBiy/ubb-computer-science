//
// Created by Alex Balta on 17.05.2024.
//

#include "Repository.hpp"

#include <fstream>
#include <sstream>
#include <utility>

void Repository::loadFromFile() {
    items.clear();

    std::ifstream in(file_name);
    if (!in.is_open()) {
        throw std::runtime_error("Can't open file: " + file_name);
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream line_stream(line);

        std::string current;
        std::vector<std::string> split;

        while (getline(line_stream, current, ',')) {
            split.push_back(current);
        }

        if (split.size() == 4) {
            int id = stoi(split[0]);
            std::string title = split[1];
            std::string author = split[2];
            int rank = stoi(split[3]);

            items.push_back({id, title, author, rank});
        }
    }

    in.close();
}

void Repository::storeToFile() {
    std::ofstream out(file_name);

    for (const Song &song : items) {
        out << song.getId() << ','
            << song.getTitle() << ','
            << song.getAuthor() << ','
            << song.getRank() << '\n';
    }

    out.close();
}

Repository::Repository(std::string file_name) : file_name{std::move(file_name)} {
    loadFromFile();
}

std::vector<Song> Repository::getAll() {
    return items;
}

void Repository::updateSong(int id, const std::string &new_title, int new_rank) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Song &song) {
        return song.getId() == id;
    });

    it->setTitle(new_title);
    it->setRank(new_rank);
    storeToFile();
}

void Repository::deleteSong(int id) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Song &song) {
        return song.getId() == id;
    });

    items.erase(it);
    storeToFile();
}

bool Repository::findSong(int id) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Song &song) {
        return song.getId() == id;
    });

    return it != items.end();
}


