//
// Created by Alex Balta on 12.06.2024.
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
            double price = stod(split[3]);

            items.push_back({id, name, type, price});
        }
    }

    in.close();
}

void Repository::storeToFile() {
    std::ofstream out(file_name);

    for (const auto &product : items) {
        out << product.getId() << ","
            << product.getName() << ","
            << product.getType() << ","
            << product.getPrice() << "\n";
    }

    out.close();
}

void Repository::addProduct(const Product &new_product) {
    items.push_back(new_product);
    storeToFile();
}
bool Repository::findProduct(int id) {
    auto it = std::find_if(items.begin(), items.end(), [id](const Product &p) {
        return p.getId() == id;
    });

    return it != items.end();
}
