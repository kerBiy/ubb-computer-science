//
// Created by Alex Balta on 17.05.2024.
//

#pragma once

#include "Repository.hpp"

class ServiceException : std::runtime_error {
  public:
    explicit ServiceException(const std::string &msg) : std::runtime_error(msg) {}
};

class Service {
  private:
    Repository &repo;
  public:
    /**
     * The main constructor
     * @param repo a reference to a repo object
     */
    explicit Service(Repository &repo);

    /**
     * Gets all the songs from the repo
     * @return all songs
     */
    std::vector<Song> getSongs();

    /**
     * Gets the length of the repo list
     * @return the length of the list
     */
    int getLen();

    /**
     * Deletes a song based on an id
     * @param id the id you want to delete
     * @throws ServiceException if there are no songs with this id
     */
    void deleteSong(int id);

    /**
     * Updates a song based on an id
     * @param id the id of the song you want to update
     * @param new_title the new title
     * @param new_rank the new rank
     * @throws ServiceException if the new_title ore the new_rank are not valid
     */
    void updateSong(int id, const std::string &new_title, int new_rank);

    /**
     * Gets a raport
     * @return a raport of rank : count
     */
    std::vector<int> raportRanks();
};
