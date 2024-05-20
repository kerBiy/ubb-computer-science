//
// Created by Alex Balta on 20.05.2024.
//

#include "Service.hpp"

std::vector<Task> Service::getAll() const {
    std::vector<Task> res(repo.getAll());

    std::sort(res.begin(), res.end(), [](const Task &t1, const Task &t2) {
        return t1.getStatus() < t2.getStatus();
    });

    return res;
}
void Service::addTask(int id, const std::string &description,
                      const std::vector<std::string> &programmers, std::string status) {
    if (description.empty() || programmers.empty() || status.empty()) {
        throw ServiceException("The forms should not be empty");
    }
    if (!(status == "open" || status == "inprogress" || status == "closed")) {
        throw ServiceException("The status should be open, inprogress or closed");
    }
    if (repo.findTask(id)) {
        throw ServiceException("There already is an task with this id.");
    }

    Task task(id, description, programmers, status);
    repo.addTask(task);
}

std::vector<Task> Service::searchByProgrammer(const std::string &name) const {
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

std::vector<Task> Service::getTasksByStatus(const std::string &status) const {
    std::vector<Task> res;

    for (const Task &task : getAll()) {
        if (task.getStatus() == status) {
            res.push_back(task);
        }
    }

    return res;
}

void Service::setTaskStatus(int id, const std::string &status) {
    repo.setTaskStatus(id, status);
}


