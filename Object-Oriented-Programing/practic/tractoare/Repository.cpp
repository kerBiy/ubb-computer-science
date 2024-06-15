//
// Created by Alex Balta on 15.06.2024.
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

        if (split.size() == 4) {
            int id = stoi(split[0]);
            std::string name = split[1];
            std::string type = split[2];
            int wheels_count = stoi(split[3]);

            items.push_back({id, name, type, wheels_count});
        }
    }

    in.close();
}

void Repository::saveToFile() {
    std::ofstream out(file_name);

    for (const auto &item : items) {
        out << item.getId() << ','
            << item.getName() << ','
            << item.getType() << ','
            << item.getWheelsCount() << '\n';
    }

    out.close();
}

void Repository::addTrack(const Track &track) {
    items.push_back(track);
    saveToFile();
}

bool Repository::findTrack(int id) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Track &t) {
        return t.getId() == id;
    });

    return it != items.end();
}

void Repository::setWheelsCount(int id, int new_count) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Track &t) {
        return t.getId() == id;
    });

    it->setWheelsCount(new_count);
    saveToFile();
}
