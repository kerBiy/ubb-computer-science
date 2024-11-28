package ro.ubbcluj.map.socialnetwork.repository;


import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.domain.validators.UtilizatorValidator;

import java.sql.*;
import java.util.*;

public class UserDBRepository implements Repository<Long, Utilizator> {

    private final UtilizatorValidator validator;
    private final Connection connection;

    public UserDBRepository(UtilizatorValidator validator, String url, String username, String password) {
        this.validator = validator;
        try {
            connection = DriverManager.getConnection(url, username, password);
        }
        catch (SQLException e)
        {
            throw new RuntimeException(e);
        }

    }

    @Override
    public Optional<Utilizator> findOne(Long longID) {
        try(PreparedStatement statement = connection.prepareStatement("select * from users " +
                    "where id = ?")

        ) {
            statement.setLong(1, longID);
            ResultSet resultSet = statement.executeQuery();
            if(resultSet.next()) {
                String username = resultSet.getString("username");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
                String password = resultSet.getString("password");
                Utilizator u = new Utilizator(username, firstName, lastName);
                u.setPassword(password);
                u.setId(longID);
                return Optional.of(u);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Utilizator> findAll() {
        List<Utilizator> users = new ArrayList<>();

        try (PreparedStatement statement = connection.prepareStatement("select * from users");
             ResultSet resultSet = statement.executeQuery()
        ) {

            while (resultSet.next())
            {
                Long id= resultSet.getLong("id");
                String username = resultSet.getString("username");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");
//                String password = resultSet.getString("password");
                Utilizator user=new Utilizator(username,firstName,lastName);
                user.setId(id);
                users.add(user);

            }
            return users;

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public Optional<Utilizator> save(Utilizator utilizator) {

        if (utilizator==null)
            throw new IllegalArgumentException("entity must be not null");

        validator.validate(utilizator);

        try (PreparedStatement statement = connection.prepareStatement(
                     "INSERT INTO users(id, username, first_name, last_name, password) VALUES (?, ?, ?, ?, ?)"
             )) {
            statement.setLong(1, utilizator.getId());
            statement.setString(2, utilizator.getUsername());
            statement.setString(3, utilizator.getFirstName());
            statement.setString(4, utilizator.getLastName());
            statement.setString(5, utilizator.getPassword());
            statement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return Optional.empty();
    }

    @Override
    public Optional<Utilizator> delete(Long aLong) {

        if (findOne(aLong).isEmpty())
            throw new IllegalArgumentException("ID inexistent");

        try {
            Statement statement = connection.createStatement();
            statement.executeUpdate("DELETE FROM users WHERE id =" + aLong);

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return Optional.empty();
    }

    @Override
    public Optional<Utilizator> update(Utilizator utilizator) {
        if (utilizator == null) {
            throw new IllegalArgumentException("Eroare, user null");
        }

        validator.validate(utilizator);

        try (PreparedStatement statement = connection.prepareStatement(
                     "UPDATE users SET first_name = ?, last_name = ? WHERE id = ?"
             )) {
            statement.setString(1, utilizator.getFirstName());
            statement.setString(2, utilizator.getLastName());
            statement.setLong(3, utilizator.getId());
            statement.executeUpdate();

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


        return Optional.empty();
    }

}


