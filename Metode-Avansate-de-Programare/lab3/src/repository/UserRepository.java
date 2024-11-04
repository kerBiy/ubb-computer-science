package repository;

import domain.User;
import validation.Validator;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class UserRepository implements Repository<Long, User> {
    private List<User> users;
    protected Validator validator;

    public UserRepository(Validator validator) {
        this.validator = validator;
        this.users = new ArrayList<>();
    }

    @Override
    public Optional<User> findOne(Long id) {
        return users.stream().filter(u -> u.getId().equals(id)).findFirst();
    }

    @Override
    public List<User> findAll() {
        return new ArrayList<>(users);
    }

    @Override
    public Optional<User> save(User entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity cannot be null.");
        }

        Optional<User> existingUser = findOne(entity.getId());
        if (existingUser.isPresent()) {
            return existingUser;
        }

        validator.validateUser(entity);

        users.add(entity);
        return Optional.empty();
    }

    @Override
    public Optional<User> delete(Long id) {
        if (id == null) {
            throw new IllegalArgumentException("ID cannot be null.");
        }

        Optional<User> userToDelete = findOne(id);
        userToDelete.ifPresent(users::remove);
        return userToDelete;
    }

    @Override
    public Optional<User> update(User entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity cannot be null.");
        }

        Optional<User> userToUpdate = findOne(entity.getId());
        if (userToUpdate.isPresent()) {
            users.remove(userToUpdate.get());
            users.add(entity);
            return Optional.empty();
        }

        return Optional.of(entity);
    }
}