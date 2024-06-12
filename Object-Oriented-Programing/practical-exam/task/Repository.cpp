//
// Created by Alex Balta on 11.06.2024.
//

#include "Repository.hpp"

#include <fstream>
#include <sstream>

void Repository::loadFromFile() {
    items.clear();

    std::ifstream in(file_name);
    if (!in.is_open()) {
        throw std::runtime_error("Can't open file: " + file_name);
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream line_stream(line);

        std::string current;
        std::vector<std::string> split;

        while (getline(line_stream, current, ',')) {
            split.push_back(current);
        }

        if (split.size() == 3) {
            int id = stoi(split[0]);
            std::string description = split[1];

            std::stringstream prog_stream(split[2]);

            std::string curr;
            std::vector<std::string> programmers;

            while (getline(prog_stream, curr, ';')) {
                programmers.push_back(curr);
            }

            std::string status = programmers.back();
            programmers.pop_back();

            Task task(id, description, programmers, status);
            items.push_back(task);
        }
    }

    in.close();
}

void Repository::storeToFile() {
    std::ofstream out(file_name);

    for (const auto &prod : items) {
        out << prod.getId() << "," << prod.getDescription() << ",";

        for (const auto &programmer : prod.getProgrammers()) {
            out << programmer << ";";
        }

        out << prod.getStatus() << "\n";
    }

    out.close();
}

void Repository::addTask(const Task &new_task) {
    items.push_back(new_task);
    storeToFile();
}

bool Repository::findTask(int id) const {
    auto it = std::find_if(items.begin(), items.end(),
                           [id](const Task &t) {
                               return t.getId() == id;
                           });

    return it != items.end();
}

void Repository::setTaskStatus(int id, const std::string &new_status) {
    auto it = std::find_if(items.begin(), items.end(),
                           [id](const Task &t) {
                               return t.getId() == id;
                           });

    it->setStatus(new_status);
    storeToFile();
}
