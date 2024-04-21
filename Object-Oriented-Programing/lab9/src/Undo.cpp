//
// Created by Alex Balta on 18.04.2024.
//

#include "Undo.hpp"

UndoAdd::UndoAdd(Library &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoAdd::doUndo() {
    auto position = lib.findBook(book.getTitle());
    lib.deleteBook(position);
}

UndoDelete::UndoDelete(Library &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoDelete::doUndo() {
    lib.addBook(book);
}

UndoUpdate::UndoUpdate(Library &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoUpdate::doUndo() {
    auto position = lib.findBook(book.getTitle());
    lib.updateBook(position, book);
}
