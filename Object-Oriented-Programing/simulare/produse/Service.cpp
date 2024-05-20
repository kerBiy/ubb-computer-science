//
// Created by Alex Balta on 19.05.2024.
//

#include "Service.hpp"

std::vector<Product> Service::getAll() {
    std::vector<Product> res(repo.getAll());

    std::sort(res.begin(), res.end(), [](const Product &p1, const Product &p2) {
        return p1.getName() < p2.getName();
    });

    return res;
}

void Service::addProduct(int id, const std::string &name, const std::string &type, double price) {
    if (name.empty() || type.empty()) {
        throw ServiceException("The input boxes cannot be empty.");
    }
    if (price < 1 || price > 100) {
        throw ServiceException("The price should be between 1 and 100.");
    }
    if (repo.findProduct(id)) {
        throw ServiceException("There already exist a product with this id.");
    }

    Product product(id, name, type, price);
    repo.addProduct(product);
}

std::vector<Product> Service::filterPrice(int max_price) {
    std::vector<Product> res;

    for (const Product &prod : getAll()) {
        if (prod.getPrice() <= max_price) {
            res.push_back(prod);
        }
    }

    return res;
}

std::map<std::string, int> Service::raportType() {
    std::map<std::string, int> res;

    for (const Product &prod : getAll()) {
        res[prod.getType()] += 1;
    }

    return res;
}
