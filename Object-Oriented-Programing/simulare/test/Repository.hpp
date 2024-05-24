//
// Created by Alex Balta on 21.05.2024.
//

#pragma once

#include "Dress.hpp"
#include <vector>

class Repository {
  private:
    std::vector<Dress> items;
    std::string file_name;

    /**
     * loads all from file
     */
    void loadFromFile();
    /**
     * writes to file
     */
    void writeToFile();

  public:
    explicit Repository(const std::string &file_name) : file_name(file_name) {
        loadFromFile();
    }

    /**
     * Gets all the dresses
     * @return a vector with all of the dresses
     */
    std::vector<Dress> getAll() const { return items; }

    /**
     * Updates valability
     * @param id the id of the dress
     * @param isValid the validity
     */
    void updateDressValidity(int id, bool isValid);
};
