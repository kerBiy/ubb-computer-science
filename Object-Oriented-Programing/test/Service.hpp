//
// Created by Alex Balta on 16.06.2024.
//

#pragma once

#include "Repository.hpp"
#include "Observer.hpp"

class Service : public Subject {
  private:
    Repository &repo;

  public:
    /**
     * The main constructor
     * @param repo the repo you want
     */
    explicit Service(Repository &repo) : repo(repo) {}

    /**
     * Gets the number of tasks in the database
     * @return the number of tasks
     */
    int getLen() const { return (int) repo.getAll().size(); }

    /**
     * Gets all of the tasks from the database
     * @return a vector with all of the tasks
     */
    std::vector<Task> getAll() const;

    /**
     * Adds a task to the database
     * @param id the id of the task
     * @param description the description of the task
     * @param programmers the programmers of the task
     * @param status the status of the task
     * @throws std::runtime_error if the inputs are not valid
     */
    void addTask(int id, const std::string &description,
                 const std::vector<std::string> &programmers, const std::string &status);

    /**
     * Searches all tasks by a programmer
     * @param programmer the name of the programmer
     * @return a vector of tasks with the programmer specified
     */
    std::vector<Task> searchByProgrammer(const std::string &programmer) const;

    /**
     * Gets the tasks by status
     * @param status the status you want
     * @return a vector of tasks with the status specified
     */
    std::vector<Task> getTasksByStatus(const std::string &status) const;

    /**
     * Sets the status to a task
     * @param id the id of the task you want to change
     * @param status the new status you want.
     * @throws std::runtime_error if the task is not found
     */
    void setTaskStatus(int id, const std::string &status);
};
