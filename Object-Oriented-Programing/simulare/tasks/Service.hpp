//
// Created by Alex Balta on 20.05.2024.
//

#pragma once

#include "Repository.hpp"

class ServiceException : public std::runtime_error {
  public:
    explicit ServiceException(const std::string &msg) : std::runtime_error(msg) {}
};

class Service {
  private:
    Repository &repo;

  public:
    explicit Service(Repository &repo) : repo(repo) {};

    int getLen() const { return repo.getAll().size(); }

    std::vector<Task> getAll() const;

    void addTask(int id,
                 const std::string &description,
                 const std::vector<std::string> &programmers,
                 std::string status);

    std::vector<Task> searchByProgrammer(const std::string &name) const;

    std::vector<Task> getTasksByStatus(const std::string &status) const;

    void setTaskStatus(int id, const std::string &status);
};
