//
// Created by Alex Balta on 21.05.2024.
//

#include "Service.hpp"

std::vector<Dress> Service::sortBySize() const {
    std::vector<Dress> res(repo.getAll());

    std::sort(res.begin(), res.end(),
              [](const Dress &d1, const Dress &d2) {
                  return d1.getSize() < d2.getSize();
              });

    return res;
}

std::vector<Dress> Service::sortByPrice() const {
    std::vector<Dress> res(repo.getAll());

    std::sort(res.begin(), res.end(),
              [](const Dress &d1, const Dress &d2) {
                  return d1.getPrice() < d2.getPrice();
              });

    return res;
}

void Service::updateDressValidity(int id, bool newValid) {
    repo.updateDressValidity(id, newValid);
}

std::vector<Dress> Service::getDressesByValidity(bool isValid) const {
    std::vector<Dress> res;

    for (const auto &dress : repo.getAll()) {
        if (dress.getValid() == isValid) {
            res.push_back(dress);
        }
    }

    return res;
}
