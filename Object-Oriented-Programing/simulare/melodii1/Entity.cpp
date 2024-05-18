//
// Created by Alex Balta on 17.05.2024.
//

#include "Entity.hpp"

#include <utility>

Song::Song(int id, std::string title, std::string author, int rank) :
    id{id}, title{std::move(title)}, author{std::move(author)}, rank{rank} {}

int Song::getId() const {
    return id;
}

std::string Song::getTitle() const {
    return title;
}

std::string Song::getAuthor() const {
    return author;
}

int Song::getRank() const {
    return rank;
}

void Song::setTitle(const std::string &new_title) {
    title = new_title;
}

void Song::setRank(int new_rank) {
    rank = new_rank;
}