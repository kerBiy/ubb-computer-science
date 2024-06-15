//
// Created by Alex Balta on 15.06.2024.
//

#pragma once

#include "Observer.hpp"
#include "Repository.hpp"

#include <map>
#include <set>

class ServiceException : public std::runtime_error {
  public:
    explicit ServiceException(const std::string &msg) : std::runtime_error(msg) {}
};

class Service : public Subject {
  private:
    Repository &repo;

  public:
    explicit Service(Repository &repo) : repo(repo) {}

    int getLen() const { return (int) repo.getAll().size(); }

    std::vector<Track> getAll() const;

    void addTrack(int id, const std::string &name, const std::string &type, int wheels_count);

    std::map<std::string, int> raportType() const;

    std::vector<Track> filterType(const std::string &type) const;

    std::set<std::string> getAllTypes() const;

    void setWheelsCount(int id, int new_count) { repo.setWheelsCount(id, new_count); }
};

