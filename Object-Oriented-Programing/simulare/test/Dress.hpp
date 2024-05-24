//
// Created by Alex Balta on 21.05.2024.
//

#pragma once

#include <string>

class Dress {
  private:
    int id;
    std::string name;
    std::string size;
    double price;
    bool valid;

  public:
    Dress(int id, std::string name, std::string size, double price, bool valid)
        : id(id), name(std::move(name)), size(std::move(size)), price(price), valid(valid) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getSize() const { return size; }
    double getPrice() const { return price; }
    bool getValid() const { return valid; }

    void setValid(bool isValid) { this->valid = isValid; }
};
