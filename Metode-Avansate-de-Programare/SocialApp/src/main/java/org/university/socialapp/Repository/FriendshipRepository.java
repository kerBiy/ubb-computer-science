package org.university.socialapp.Repository;

import org.university.socialapp.Domain.Friendship;
import org.university.socialapp.Domain.Validation.FriendshipValidator;

import java.sql.*;
import java.util.Optional;
import java.util.ArrayList;
import java.util.List;

public class FriendshipRepository implements Repository<String, Friendship> {
    private final String url;
    private final String user;
    private final String password;
    private FriendshipValidator validator;

    public FriendshipRepository(FriendshipValidator validator, String url, String user, String password) {
        this.url = url;
        this.user = user;
        this.password = password;
        this.validator = validator;
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, user, password);
    }

    @Override
    public Optional<Friendship> findOne(String id) {
        String query = "SELECT user1, user2 FROM Friendships WHERE user1 = ? AND user2 = ?";
        String[] ids = id.split("-");

        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, Long.parseLong(ids[0]));
            statement.setLong(2, Long.parseLong(ids[1]));
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Long user1 = resultSet.getLong("user1");
                Long user2 = resultSet.getLong("user2");
                Friendship friendship = new Friendship(user1, user2);
                return Optional.of(friendship);
            }
        } catch (SQLException e) {
            System.out.println("Error fetching friendship: " + e.getMessage());
        }
        return Optional.empty();
    }

    @Override
    public List<Friendship> findAll() {
        List<Friendship> friendships = new ArrayList<>();
        String query = "SELECT user1, user2 FROM Friendships";

        try (Connection connection = getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(query)) {
            while (resultSet.next()) {
                Long user1 = resultSet.getLong("user1");
                Long user2 = resultSet.getLong("user2");
                friendships.add(new Friendship(user1, user2));
            }
        } catch (SQLException e) {
            System.out.println("Error fetching all friendships: " + e.getMessage());
        }
        return friendships;
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

        validator.validate(entity);

        String query = "INSERT INTO Friendships (user1, user2) VALUES (?, ?)";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, entity.getUser1());
            statement.setLong(2, entity.getUser2());
            statement.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            System.out.println("Error saving friendship: " + e.getMessage());
            return Optional.of(entity);
        }
    }

    @Override
    public Optional<Friendship> delete(String id) {
        Optional<Friendship> friendship = findOne(id);
        if (friendship.isPresent()) {
            String query = "DELETE FROM Friendships WHERE user1 = ? AND user2 = ?";
            String[] ids = id.split("-");

            try (Connection connection = getConnection();
                 PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setLong(1, Long.parseLong(ids[0]));
                statement.setLong(2, Long.parseLong(ids[1]));
                statement.executeUpdate();
            } catch (SQLException e) {
                System.out.println("Error deleting friendship: " + e.getMessage());
            }
        }
        return friendship;
    }

    @Override
    public Optional<Friendship> update(Friendship entity) {
        // Assuming you want to implement an update method if necessary
        return Optional.empty(); // Currently a placeholder
    }
}