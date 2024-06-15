//
// Created by Alex Balta on 18.05.2024.
//

#pragma once

#include "Song.hpp"
#include <utility>
#include <vector>

class Repository {
  private:
    std::vector<Song> items;
    std::string file_name;

    void loadFromFile();
    void writeToFile();
  public:
    explicit Repository(std::string file_name) : file_name(std::move(file_name)) {
        loadFromFile();
    }

    std::vector<Song> getAll() { return items; }

    void addSong(const Song &song);
    void deleteSong(int id);
    void updateSong(int id, const Song &new_song);
    bool findSong(int id);
};
