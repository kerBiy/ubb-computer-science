package org.university.socialapp.Repository;
import org.university.socialapp.Domain.Entity;
import org.university.socialapp.Validation.ValidationException;

import java.util.Optional;

/**
 * CRUD operations repository interface.
 * @param <ID> - type of the ID, which must be unique.
 * @param <E> - type of entities saved in the repository.
 */
public interface Repository<ID, E extends Entity<ID>> {

    /**
     * Finds an entity by its ID.
     * @param id - the ID of the entity to be returned; must not be null.
     * @return an {@code Optional} encapsulating the entity with the given ID,
     * or {@code Optional.empty()} if no entity exists with the given ID.
     * @throws IllegalArgumentException if ID is null.
     */
    Optional<E> findOne(ID id);

    /**
     * Retrieves all entities.
     * @return an {@code Iterable} containing all entities in the repository.
     */
    Iterable<E> findAll();

    /**
     * Saves the given entity.
     * @param entity - entity to save; must not be null.
     * @return an {@code Optional} - {@code Optional.empty()} if the entity was saved,
     * or the existing entity if an entity with the same ID already exists.
     * @throws ValidationException if the entity is not valid.
     * @throws IllegalArgumentException if the given entity is null.
     */
    Optional<E> save(E entity);

    /**
     * Removes the entity with the specified ID.
     * @param id - the ID of the entity to remove; must not be null.
     * @return an {@code Optional} - {@code Optional.empty()} if there is no entity with the given ID,
     * or the removed entity otherwise.
     * @throws IllegalArgumentException if the given ID is null.
     */
    Optional<E> delete(ID id);

    /**
     * Updates the given entity.
     * @param entity - entity to update; must not be null.
     * @return an {@code Optional} - {@code Optional.empty()} if the entity was updated successfully,
     * or the existing entity if the ID does not exist.
     * @throws IllegalArgumentException if the given entity is null.
     * @throws ValidationException if the entity is not valid.
     */
    Optional<E> update(E entity);
}