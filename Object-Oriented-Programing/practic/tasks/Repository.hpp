//
// Created by Alex Balta on 20.05.2024.
//
#pragma once

#include "Task.hpp"
#include <vector>

class Repository {
  private:
    std::vector<Task> items;
    std::string file_name;

    void loadFromFile();
    void writeToFile();
  public:
    explicit Repository(std::string file_name) : file_name(std::move(file_name)) {
        loadFromFile();
    }

    std::vector<Task> getAll() { return items; }

    void addTask(const Task &task);
    bool findTask(int id);
    void setTaskStatus(int id, const std::string &status);
};

