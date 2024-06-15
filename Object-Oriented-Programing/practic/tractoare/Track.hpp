//
// Created by Alex Balta on 15.06.2024.
//

#pragma once

#include <string>

class Track {
  private:
    int id;
    std::string name;
    std::string type;
    int wheels_count;

  public:
    Track(int id, std::string name, std::string type, int wheels_count)
        : id(id), name(std::move(name)), type(std::move(type)), wheels_count(wheels_count) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getWheelsCount() const { return wheels_count; }

    void setWheelsCount(int new_count) { this->wheels_count = new_count; }
};
