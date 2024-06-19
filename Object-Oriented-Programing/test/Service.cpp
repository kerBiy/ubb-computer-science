//
// Created by Alex Balta on 16.06.2024.
//

#include "Service.hpp"

std::vector<Task> Service::getAll() const {
    std::vector<Task> res(repo.getAll());

    std::sort(res.begin(), res.end(), [](const Task &t1, const Task &t2) {
        return t1.getStatus() > t2.getStatus();
    });

    return res;
}

void Service::addTask(int id,
                      const std::string &description,
                      const std::vector<std::string> &programmers,
                      const std::string &status) {
    if (repo.findTask(id)) {
        throw std::runtime_error("There already exists a task with this id");
    }
    if (description.empty()) {
        throw std::runtime_error("The description should not be empty");
    }
    if (!(status == "open" || status == "inprogress" || status == "closed")) {
        throw std::runtime_error("The status should be Open, Inprogress or Closed");
    }
    if (!(1 <= programmers.size() && programmers.size() <= 4)) {
        throw std::runtime_error("There should be between 1 and 4 programmers");
    }

    Task new_task(id, description, programmers, status);
    repo.addTask(new_task);
    notify();
}

std::vector<Task> Service::searchByProgrammer(const std::string &programmer) const {
    std::vector<Task> res;

    for (const auto &item : getAll()) {
        for (const auto &p : item.getProgrammers()) {
            if (p.find(programmer) != std::string::npos) {
                res.push_back(item);
                break;
            }
        }
    }

    return res;
}

std::vector<Task> Service::getTasksByStatus(const std::string &status) const {
    std::vector<Task> res;

    for (const auto &item : getAll()) {
        if (item.getStatus() == status) {
            res.push_back(item);
        }
    }

    return res;
}

void Service::setTaskStatus(int id, const std::string &status) {
    if (!repo.findTask(id)) {
        throw std::runtime_error("The task doesn't exist");
    }
    if (status.empty()) {
        throw std::runtime_error("The status should not be empty");
    }

    repo.setTaskStatus(id, status);
    notify();
}
