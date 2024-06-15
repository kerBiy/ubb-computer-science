//
// Created by Alex Balta on 21.05.2024.
//

#pragma once

#include "Repository.hpp"

class Service {
  private:
    Repository &repo;

  public:
    explicit Service(Repository &repo) : repo(repo) {}

    /**
     * Gets the len
     * @return the len of the items
     */
    int getLen() const { return repo.getAll().size(); }

    /**
     * Gets all items
     * @return a vector with all the dresses
     */
    std::vector<Dress> getAll() const { return repo.getAll(); }

    /**
     * Sorts the dresses by size
     * @return a vector of dresses sorted by size
     */
    std::vector<Dress> sortBySize() const;

    /**
     * Sorts the dresses by price
     * @return a vector of dresses sorted by price
     */
    std::vector<Dress> sortByPrice() const;

    /**
     * Updates the validity of the dress
     * @param id
     * @param newValid
     */
    void updateDressValidity(int id, bool newValid);

    /**
     * Gets all dresses by validity
     * @param isValid
     * @return
     */
    std::vector<Dress> getDressesByValidity(bool isValid) const;
};
