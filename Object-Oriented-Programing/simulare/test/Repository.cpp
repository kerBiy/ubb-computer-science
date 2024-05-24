//
// Created by Alex Balta on 21.05.2024.
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

        if (split.size() == 5) {
            int id = stoi(split[0]);
            std::string name = split[1];
            std::string size = split[2];
            double price = stod(split[3]);
            bool valid = split[4] == "True";

            Dress new_dress(id, name, size, price, valid);
            items.push_back(new_dress);
        }
    }

    in.close();
}

void Repository::writeToFile() {
    std::ofstream out(file_name);

    for (const auto &dress : items) {
        out << dress.getId() << ","
            << dress.getName() << ","
            << dress.getSize() << ","
            << dress.getPrice() << ",";

        std::string valid = (dress.getValid()) ? "True" : "False";
        out << valid << "\n";
    }

    out.close();
}

void Repository::updateDressValidity(int id, bool isValid) {
    auto it = std::find_if(items.begin(), items.end(),
                           [id](const Dress &d) {
                               return d.getId() == id;
                           });

    it->setValid(isValid);
    writeToFile();
}
