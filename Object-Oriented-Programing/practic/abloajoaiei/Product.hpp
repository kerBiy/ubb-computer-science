//
// Created by Alex Balta on 12.06.2024.
//

#pragma once

#include <string>
#include <utility>

class Product {
  private:
    int id;
    std::string name;
    std::string type;
    double price;
  public:
    Product(int id, std::string name, std::string type, double price)
        : id(id), name(std::move(name)), type(std::move(type)), price(price) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    double getPrice() const { return price; }
};
