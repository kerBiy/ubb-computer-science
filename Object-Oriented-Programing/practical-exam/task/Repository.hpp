//
// Created by Alex Balta on 11.06.2024.
//

#pragma once

#include <utility>

#include "Task.hpp"

class Repository {
  private:
    std::vector<Task> items;
    std::string file_name;

    void loadFromFile();
    void storeToFile();

  public:
    explicit Repository(std::string file_name) : file_name(std::move(file_name)) {
        loadFromFile();
    }

    std::vector<Task> getAll() const { return items; }

    void addTask(const Task &new_task);
    bool findTask(int id) const;
    void setTaskStatus(int id, const std::string &new_status);
};
