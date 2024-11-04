package repository;

import domain.Friendship;
import validation.Validator;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class FriendshipRepository implements Repository<String, Friendship> {
    private List<Friendship> friendships;
    private Validator validator;

    public FriendshipRepository(Validator validator) {
        this.validator = validator;
        friendships = new ArrayList<>();
    }

    @Override
    public Optional<Friendship> findOne(String id) {
        return friendships.stream().filter(f -> f.getId().equals(id)).findFirst();
    }

    @Override
    public List<Friendship> findAll() {
        return new ArrayList<>(friendships);
    }

    @Override
    public Optional<Friendship> save(Friendship entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity cannot be null.");
        }

        Optional<Friendship> existingFriendship = findOne(entity.getId());
        if (existingFriendship.isPresent()) {
            return existingFriendship;
        }

        friendships.add(entity);
        return Optional.empty();
    }

    @Override
    public Optional<Friendship> delete(String id) {
        Optional<Friendship> friendshipToDelete = findOne(id);
        friendshipToDelete.ifPresent(friendships::remove);
        return friendshipToDelete;
    }

    @Override
    public Optional<Friendship> update(Friendship entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity cannot be null.");
        }

        Optional<Friendship> friendshipToUpdate = findOne(entity.getId());
        if (friendshipToUpdate.isPresent()) {
            friendships.remove(friendshipToUpdate.get());
            friendships.add(entity);
            return Optional.empty();
        }

        return Optional.of(entity);
    }
}