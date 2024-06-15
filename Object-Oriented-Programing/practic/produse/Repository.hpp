//
// Created by Alex Balta on 19.05.2024.
//

#pragma once

#include "Product.hpp"
#include <utility>
#include <vector>

class Repository {
  private:
    std::vector<Product> items;
    std::string file_name;

    void loadFromFile();
    void writeToFile();
  public:
    explicit Repository(std::string file_name) : file_name(std::move(file_name)) {
        loadFromFile();
    }

    std::vector<Product> getAll() { return items; }

    void addProduct(const Product &product);
    bool findProduct(int id);
};
