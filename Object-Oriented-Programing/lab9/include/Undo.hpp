//
// Created by Alex Balta on 18.04.2024.
//

#pragma once

#include "Repository.hpp"

class AbstractUndo {
  public:
    /**
     * Undo the action performed by this class.
     */
    virtual void doUndo() = 0;
    virtual ~AbstractUndo() = default;
};

class UndoAdd : public AbstractUndo {
  private:
    Book book;
    Library &lib;
  public:
    /**
     * Constructs an UndoAdd object.
     * @param lib Reference to the library where the book was added.
     * @param book The book that was added.
     */
    UndoAdd(Library &lib, Book book);
    void doUndo() override;
};

class UndoDelete : public AbstractUndo {
  private:
    Book book;
    Library &lib;
  public:
    /**
     * Constructs an UndoDelete object.
     * @param lib Reference to the library where the book was deleted.
     * @param book The book that was deleted.
     */
    UndoDelete(Library &lib, Book book);
    void doUndo() override;
};

class UndoUpdate : public AbstractUndo {
  private:
    Book book;
    Library &lib;
  public:
    /**
     * Constructs an UndoUpdate object.
     * @param lib Reference to the library where the book was updated.
     * @param book The book's old state.
     */
    UndoUpdate(Library &lib, Book book);
    void doUndo() override;
};
