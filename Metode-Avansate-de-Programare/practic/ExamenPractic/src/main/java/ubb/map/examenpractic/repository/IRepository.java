package ubb.map.examenpractic.repository;


import ubb.map.examenpractic.domain.Entity;

import java.util.Optional;

public interface IRepository<ID, E extends Entity<ID>> {
    Optional<E> findOne(ID id);

    Iterable<E> findAll();
}