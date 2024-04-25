//
// Created by Alex Balta on 18.04.2024.
//

#include "Undo.hpp"

UndoAdd::UndoAdd(AbstractLibrary &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoAdd::doUndo() {
    lib.deleteBook(book.getTitle());
}

UndoDelete::UndoDelete(AbstractLibrary &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoDelete::doUndo() {
    lib.addBook(book);
}

UndoUpdate::UndoUpdate(AbstractLibrary &lib, Book book) : book{std::move(book)}, lib{lib} {}

void UndoUpdate::doUndo() {
    lib.updateBook(book.getTitle(), book);
}
