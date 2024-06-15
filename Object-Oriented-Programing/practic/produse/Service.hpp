//
// Created by Alex Balta on 19.05.2024.
//

#pragma once

#include "Repository.hpp"
#include <map>

class ServiceException : public std::runtime_error {
  public:
    explicit ServiceException(const std::string &msg) : std::runtime_error(msg) {}
};

class Service {
  private:
    Repository &repo;

  public:
    explicit Service(Repository &repo) : repo(repo) {}

    int getLen() { return repo.getAll().size(); }

    std::vector<Product> getAll();

    void addProduct(int id, const std::string &name, const std::string &type, double price);

    std::vector<Product> filterPrice(int max_price);

    std::map<std::string, int> raportType();
};
