package org.university.socialapp.Repository;

import org.university.socialapp.Domain.Friendship;
import org.university.socialapp.Domain.Validation.FriendshipValidator;
import org.university.socialapp.Utils.Page;
import org.university.socialapp.Utils.Pageable;

import java.sql.*;
import java.time.LocalDateTime;
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
        String query = "SELECT user1, user2, status, date FROM Friendships WHERE user1 = ? AND user2 = ?";
        String[] ids = id.split("-");

        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {

            statement.setString(1, ids[0]);
            statement.setString(2, ids[1]);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String user1 = resultSet.getString("user1");
                String user2 = resultSet.getString("user2");
                String status = resultSet.getString("status");
                LocalDateTime date = resultSet.getTimestamp("date").toLocalDateTime();
                Friendship friendship = new Friendship(user1, user2, status, date);
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
        String query = "SELECT user1, user2, status, date FROM Friendships";

        try (Connection connection = getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(query)) {
            while (resultSet.next()) {
                String user1 = resultSet.getString("user1");
                String user2 = resultSet.getString("user2");
                String status = resultSet.getString("status");
                LocalDateTime date = resultSet.getTimestamp("date").toLocalDateTime();
                friendships.add(new Friendship(user1, user2, status, date));
            }
        } catch (SQLException e) {
            System.out.println("Error fetching all friendships: " + e.getMessage());
        }
        return friendships;
    }

    @Override
    public Optional<Friendship> save(Friendship friendship) {
        if (friendship == null) {
            throw new IllegalArgumentException("Entity cannot be null.");
        }

        Optional<Friendship> existingFriendship = findOne(friendship.getId());
        if (existingFriendship.isPresent()) {
            return existingFriendship;
        }

        validator.validate(friendship);

        String query = "INSERT INTO Friendships (user1, user2, status, date) VALUES (?, ?, ?, ?)";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, friendship.getUser1());
            statement.setString(2, friendship.getUser2());
            statement.setString(3, friendship.getStatus());
            statement.setDate(4, java.sql.Date.valueOf(friendship.getDate().toLocalDate()));
            statement.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            System.out.println("Error saving friendship: " + e.getMessage());
            return Optional.of(friendship);
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
                statement.setString(1, ids[0]);
                statement.setString(2, ids[1]);
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

//    @Override
//    public Page<Friendship> findAllOnPage(Pageable pageable) {
//        List<E> entitiesOnPage = new ArrayList<>();
//        String sql = "SELECT * FROM " + database + " LIMIT ? OFFSET ?";
//        try {
//            PreparedStatement stm = db_connection.prepareStatement(sql);
//            stm.setInt(1, pageable.getPageSize());
//            stm.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
//            ResultSet rs = stm.executeQuery();
//            while (rs.next()) {
//                E e = resultToEntity(rs);
//                entitiesOnPage.add(e);
//            }
//        } catch (SQLException e) {
//            throw new RuntimeException(e);
//        }
//        return new Page<>(entitiesOnPage, getCount());
//    }
}