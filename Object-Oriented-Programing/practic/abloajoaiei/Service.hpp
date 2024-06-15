//
// Created by Alex Balta on 12.06.2024.
//

#pragma once

#include "Repository.hpp"
#include <unordered_map>

#include "Observer.hpp"

class Service : public Subject {
  private:
    Repository &repo;

  public:
    explicit Service(Repository &repo) : repo(repo) {}

    int getLen() const { return (int) repo.getAll().size(); }

    std::vector<Product> getAll() const;

    void addProduct(int id, std::string name, std::string type, double price);

    std::vector<Product> filterByPrice(int min_price) const;

    std::unordered_map<std::string, int> getRaport() const;
};
