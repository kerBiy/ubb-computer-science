//
// Created by Alex Balta on 19.05.2024.
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

        if (split.size() == 4) {
            int id = stoi(split[0]);
            std::string name = split[1];
            std::string type = split[2];
            double price = stod(split[3]);

            Product product(id, name, type, price);
            items.push_back(product);
        }
    }

    in.close();
}

void Repository::writeToFile() {
    std::ofstream out(file_name);

    for (const Product &prod : items) {
        out << prod.getId() << ","
            << prod.getName() << ","
            << prod.getType() << ","
            << prod.getPrice() << "\n";
    }

    out.close();
}

void Repository::addProduct(const Product &product) {
    items.push_back(product);
    writeToFile();
}

bool Repository::findProduct(int id) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Product &p) {
        return p.getId() == id;
    });

    return it != items.end();
}
