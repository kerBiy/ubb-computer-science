//
// Created by Alex Balta on 17.05.2024.
//

#pragma once

#include <string>

class Song {
  private:
    int id;
    std::string title;
    std::string author;
    int rank;
  public:
    /**
     * The main constructor
     * @param id the id of the song
     * @param title the title of the song
     * @param author the author of the song
     * @param rank the rank of the song
     */
    Song(int id, std::string title, std::string author, int rank);

    /**
     * Gets the id
     * @return a number representing the id
     */
    int getId() const;

    /**
     * Gets the title
     * @return a string representing the title
     */
    std::string getTitle() const;

    /**
     * Gets the author
     * @return a string representing the author
     */
    std::string getAuthor() const;

    /**
     * Gets the rank
     * @return a number representing the rank
     */
    int getRank() const;

    /**
     * Sets the title
     * @param new_title the new title
     */
    void setTitle(const std::string &new_title);

    /**
     * Sets the rank
     * @param new_rank the new rank
     */
    void setRank(int new_rank);
};
