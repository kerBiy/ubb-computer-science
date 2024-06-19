//
// Created by Alex Balta on 16.06.2024.
//

#include "Repository.hpp"

#include <sstream>
#include <fstream>

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

        if (split.size() >= 4) {
            int id = stoi(split[0]);
            std::string description = split[1];
            std::string genre = split.back();

            std::vector<std::string> programmers;
            for (size_t i = 2; i < split.size() - 1; ++i) {
                programmers.push_back(split[i]);
            }

            items.push_back({id, description, programmers, genre});
        }
    }

    in.close();
}

void Repository::storeToFile() {
    std::ofstream out(file_name);

    for (const auto &item : items) {
        out << item.getId() << ',' << item.getDescription() << ',';

        for (const auto &programmer : item.getProgrammers()) {
            out << programmer << ',';
        }

        out << item.getStatus() << '\n';
    }

    out.close();

}

void Repository::addTask(const Task &new_task) {
    items.push_back(new_task);
    storeToFile();
}

bool Repository::findTask(int id) const {
    auto it = std::find_if(items.begin(), items.end(), [id](const Task &t) {
        return t.getId() == id;
    });

    return it != items.end();
}

void Repository::setTaskStatus(int id, const std::string &status) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Task &t) {
        return t.getId() == id;
    });

    it->setStatus(status);
    storeToFile();
}
