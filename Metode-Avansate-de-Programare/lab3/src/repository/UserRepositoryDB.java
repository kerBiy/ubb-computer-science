package repository;

import domain.User;
import validation.Validator;

import java.sql.*;
import java.util.Optional;
import java.util.ArrayList;
import java.util.List;

public class UserRepositoryDB extends UserRepository {
    private final String url;
    private final String user;
    private final String password;

    public UserRepositoryDB(Validator validator, String url, String user, String password) {
        super(validator);
        this.url = url;
        this.user = user;
        this.password = password;
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, user, password);
    }

    @Override
    public Optional<User> findOne(Long id) {
        String query = "SELECT * FROM Users WHERE id = ?";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Long userId = resultSet.getLong("id");
                String name = resultSet.getString("name");
                String email = resultSet.getString("email");
                User user = new User(userId, name, email);
                return Optional.of(user);
            }
        } catch (SQLException e) {
            System.out.println("Error fetching user: " + e.getMessage());
        }
        return Optional.empty();
    }

    @Override
    public List<User> findAll() {
        List<User> users = new ArrayList<>();
        String query = "SELECT * FROM Users";
        try (Connection connection = getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(query)) {
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String name = resultSet.getString("name");
                String email = resultSet.getString("email");
                users.add(new User(id, name, email));
            }
        } catch (SQLException e) {
            System.out.println("Error fetching all users: " + e.getMessage());
        }
        return users;
    }

    @Override
    public Optional<User> save(User user) {
        if (user == null) {
            throw new IllegalArgumentException("Entity cannot be null.");
        }

        Optional<User> existingUser = findOne(user.getId());
        if (existingUser.isPresent()) {
            return existingUser;
        }

        validator.validateUser(user);

        String query = "INSERT INTO Users (id, name, email) VALUES (?, ?, ?)";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, user.getId());
            statement.setString(2, user.getName());
            statement.setString(3, user.getEmail());
            statement.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            System.out.println("Error saving user: " + e.getMessage());
            return Optional.of(user);
        }
    }

    @Override
    public Optional<User> delete(Long id) {
        if (id == null) {
            throw new IllegalArgumentException("ID cannot be null.");
        }

        Optional<User> user = findOne(id);
        if (user.isPresent()) {
            String query = "DELETE FROM Users WHERE id = ?";
            try (Connection connection = getConnection();
                 PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setLong(1, id);
                statement.executeUpdate();
            } catch (SQLException e) {
                System.out.println("Error deleting user: " + e.getMessage());
            }
        }
        return user;
    }

    @Override
    public Optional<User> update(User user) {
        String query = "UPDATE Users SET name = ?, email = ? WHERE id = ?";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, user.getName());
            statement.setString(2, user.getEmail());
            statement.setLong(3, user.getId());
            int rowsUpdated = statement.executeUpdate();
            if (rowsUpdated > 0) {
                return Optional.empty();
            }
        } catch (SQLException e) {
            System.out.println("Error updating user: " + e.getMessage());
        }
        return Optional.of(user);
    }
}