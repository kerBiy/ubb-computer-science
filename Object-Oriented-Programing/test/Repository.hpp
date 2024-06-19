//
// Created by Alex Balta on 16.06.2024.
//

#pragma once

#include "Task.hpp"

class Repository {
  private:
    std::vector<Task> items;
    std::string file_name;

    /*
     * Loads all items from the database.
     */
    void loadFromFile();

    /**
     * Stores all items into the database.
     */
    void storeToFile();

  public:
    /**
     * The main constructor, loads all the data from the database
     * @param file_name the name of the file containing the database
     */
    explicit Repository(const std::string &file_name) : file_name(file_name) {
        loadFromFile();
    }

    /**
     * Gets all tasks
     * @return a vector with all the tasks
     */
    std::vector<Task> getAll() const { return items; }

    /**
     * Adds a task to the database
     * @param new_task the task you want to add
     */
    void addTask(const Task &new_task);

    /**
     * Finds if a task exists in the database
     * @param id the id of the task you want
     * @return true if the task is in the database
     */
    bool findTask(int id) const;

    /**
     * Set a status to a task
     * @param id the id of the task you want
     * @param status the new status you want
     */
    void setTaskStatus(int id, const std::string &status);
};
