//
// Created by Alex Balta on 18.05.2024.
//

#pragma once

#include <string>

class Song {
  private:
    int id;
    std::string title;
    std::string artist;
    std::string genre;

  public:
    Song(int id, std::string title, std::string artist, std::string genre)
        : id(id), title(std::move(title)), artist(std::move(artist)), genre(std::move(genre)) {}

    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getGenre() const { return genre; }
};
