//
// Created by Alex Balta on 12.06.2024.
//

#pragma once

#include "Product.hpp"
#include <utility>
#include <vector>

class Repository {
  private:
    std::string file_name;
    std::vector<Product> items;

    void loadFromFile();
    void storeToFile();

  public:
    explicit Repository(std::string file_name) : file_name(std::move(file_name)) {
        loadFromFile();
    }

    std::vector<Product> getAll() const { return items; }

    void addProduct(const Product &new_product);
    bool findProduct(int id);
};
