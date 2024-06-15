//
// Created by Alex Balta on 18.05.2024.
//

#pragma once

#include "Repository.hpp"
#include "Observer.hpp"
#include <map>

class ServiceException : public std::runtime_error {
  public:
    explicit ServiceException(const std::string &msg) : std::runtime_error(msg) {}
};

class Service : public Subject {
  private:
    Repository &repo;

    int generateUniqId() const;
  public:
    explicit Service(Repository &repo) : repo(repo) {}

    int getLen() const { return repo.getAll().size(); }

    std::vector<Song> getAll() const;

    void addSong(const std::string &title, const std::string &artist, const std::string &genre);

    void deleteSong(int id);

    void updateSong(int id, const std::string &title, const std::string &artist, const std::string &genre);

    std::map<std::string, int> raportArtist() const;

    std::map<std::string, int> raportGenre() const;
};
