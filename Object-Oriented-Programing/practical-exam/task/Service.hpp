//
// Created by Alex Balta on 11.06.2024.
//

#pragma once

#include "Repository.hpp"
#include "Observer.hpp"

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

    std::vector<Task> getAll() const;

    void addTask(int id, const std::string &description,
                 const std::vector<std::string> &programmers, const std::string &status);

    std::vector<Task> searchByProgrammer(const std::string &name);

    std::vector<Task> getTasksByStatus(const std::string &status);

    void setTaskStatus(int id, const std::string &new_status);
};
