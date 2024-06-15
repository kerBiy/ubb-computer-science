//
// Created by Alex Balta on 17.05.2024.
//

#pragma once

#include "Entity.hpp"
#include <vector>

class Repository {
  private:
    std::vector<Song> items;
    std::string file_name;

    /**
     * Loads all of the songs from the database
     */
    void loadFromFile();

    /**
     * Stores all of the songs in the database
     */
    void storeToFile();

  public:
    /**
     * The main constructor
     * @param file_name the name of the database
     */
    explicit Repository(std::string file_name);

    /**
     * Gets all of the songs
     * @return a vector with all of the songs
     */
    std::vector<Song> getAll();

    /**
     * Deletes a song
     * @param id the id of the song you want to delete
     */
    void deleteSong(int id);

    /**
     * Updates a song
     * @param id the id of the song you want to update
     * @param new_title the new title
     * @param new_rank the new rank
     */
    void updateSong(int id, const std::string &new_title, int new_rank);

    /**
     * Finds a song
     * @param id the id of the song you want to find
     * @return true if the song exists, false otherwise
     */
    bool findSong(int id);
};
