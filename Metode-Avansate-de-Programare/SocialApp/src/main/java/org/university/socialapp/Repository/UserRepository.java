package org.university.socialapp.Repository;

import org.university.socialapp.Domain.User;
import org.university.socialapp.Domain.Validation.UserValidator;

import java.sql.*;
import java.util.Optional;
import java.util.ArrayList;
import java.util.List;

public class UserRepository implements Repository<String, User> {
    private final String url;
    private final String user;
    private final String password;
    private UserValidator validator;

    public UserRepository(UserValidator validator, String url, String user, String password) {
        this.url = url;
        this.user = user;
        this.password = password;
        this.validator = validator;
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, user, password);
    }

    @Override
    public Optional<User> findOne(String name) {
        String query = "SELECT * FROM Users WHERE name = ?";

        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {

            statement.setString(1, name);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String password = resultSet.getString("password");
                User user = new User(name, password);
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
                String name = resultSet.getString("name");
                String password = resultSet.getString("password");
                users.add(new User(name, password));
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

        validator.validate(user);

        String query = "INSERT INTO Users (name, password) VALUES (?, ?)";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(query)) {

            statement.setString(1, user.getName());
            statement.setString(2, user.getPassword());
            statement.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            System.out.println("Error saving user: " + e.getMessage());
            return Optional.of(user);
        }
    }

    @Override
    public Optional<User> delete(String name) {
        if (name == null) {
            throw new IllegalArgumentException("ID cannot be null.");
        }

        Optional<User> user = findOne(name);
        if (user.isPresent()) {
            String query = "DELETE FROM Users WHERE name = ?";
            try (Connection connection = getConnection();
                 PreparedStatement statement = connection.prepareStatement(query)) {

                statement.setString(1, name);
                statement.executeUpdate();
            } catch (SQLException e) {
                System.out.println("Error deleting user: " + e.getMessage());
            }
        }

        return user;
    }

    @Override
    public Optional<User> update(User user) {
        return Optional.of(user);
    }
}