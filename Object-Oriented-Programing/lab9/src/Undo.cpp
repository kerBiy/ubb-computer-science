//
// Created by Alex Balta on 18.04.2024.
//

#include "Undo.hpp"

#include <utility>

UndoAdd::UndoAdd(Library &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoAdd::doUndo() {
    auto iter = lib.findBook(book.getTitle());
    lib.deleteBook(iter);
}

UndoDelete::UndoDelete(Library &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoDelete::doUndo() {
    lib.addBook(book);
}

UndoUpdate::UndoUpdate(Library &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoUpdate::doUndo() {
    auto iter = lib.findBook(book.getTitle());
    lib.updateBook(iter, book);
}
