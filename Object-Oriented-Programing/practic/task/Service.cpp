//
// Created by Alex Balta on 11.06.2024.
//

#include "Service.hpp"

std::vector<Task> Service::getAll() const {
    std::vector<Task> output(repo.getAll());

    std::sort(output.begin(), output.end(),
              [](const Task &t1, const Task &t2) {
                  return t1.getStatus() < t2.getStatus();
              });

    return output;
}

void Service::addTask(int id, const std::string &description,
                      const std::vector<std::string> &programmers, const std::string &status) {
    if (description.empty() || programmers.empty() || status.empty()) {
        throw ServiceException("The fields should not be empty.");
    }
    if (!(status == "open" || status == "inprogress" || status == "closed")) {
        throw ServiceException("The task status should be open, inprogress or closed.");
    }
    if (repo.findTask(id)) {
        throw ServiceException("An task with this id already exists.");
    }

    Task new_task(id, description, programmers, status);
    repo.addTask(new_task);
    notify();
}

std::vector<Task> Service::searchByProgrammer(const std::string &name) {
    if (name.empty()) {
        throw ServiceException("The forms should not be empty");
    }

    std::vector<Task> res;

    for (const Task &task : getAll()) {
        for (const std::string &programmer : task.getProgrammers()) {
            if (programmer.find(name) != std::string::npos) {
                res.push_back(task);
                break;
            }
        }
    }

    return res;
}

std::vector<Task> Service::getTasksByStatus(const std::string &status) {
    std::vector<Task> res;

    for (const Task &task : getAll()) {
        if (task.getStatus() == status) {
            res.push_back(task);
        }
    }

    return res;
}

void Service::setTaskStatus(int id, const std::string &new_status) {
    repo.setTaskStatus(id, new_status);
    notify();
}