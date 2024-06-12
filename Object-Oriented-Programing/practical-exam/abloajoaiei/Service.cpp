//
// Created by Alex Balta on 12.06.2024.
//

#include "Service.hpp"

std::vector<Product> Service::getAll() const {
    std::vector<Product> output(repo.getAll());

    std::sort(output.begin(), output.end(), [](const Product &p1, const Product &p2) {
        return p1.getPrice() < p2.getPrice();
    });

    return output;
}

void Service::addProduct(int id, std::string name, std::string type, double price) {
    std::string error;

    if (name.empty() || type.empty()) {
        error.append("Args cannot be empty\n");
    }
    if (!(1 <= price && price <= 100)) {
        error.append("Price must be between 1 and 100\n");
    }
    if (repo.findProduct(id)) {
        error.append("There already exists a product with this id\n");
    }

    if (!error.empty()) {
        throw std::runtime_error(error);
    }

    Product new_product(id, name, type, price);
    repo.addProduct(new_product);

    notify();
}

std::vector<Product> Service::filterByPrice(int min_price) const {
    std::vector<Product> output;
    std::vector<Product> all_books(getAll());

    std::copy_if(all_books.begin(),
                 all_books.end(),
                 std::back_inserter(output),
                 [min_price](const Product &prod) {
                     return prod.getPrice() >= min_price;
                 });

    return output;
}

std::unordered_map<std::string, int> Service::getRaport() const {
    std::unordered_map<std::string, int> output;

    for (const auto &prod : repo.getAll()) {
        output[prod.getType()] += 1;
    }

    return output;
}
