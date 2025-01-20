package ubb.map.practiczbor.repository;

import ubb.map.practiczbor.domain.Client;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class ClientRepository implements IRepository<String, Client> {
    private final Connection connection;

    public ClientRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Client> findOne(String id) {
        String sql = "SELECT * FROM client WHERE username = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Client(
                        rs.getString("username"),
                        rs.getString("name")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Client> findAll() {
        String sql = "SELECT * FROM client";
        ArrayList<Client> clients = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                clients.add(new Client(
                        rs.getString("username"),
                        rs.getString("name")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return clients;
    }

    @Override
    public Optional<Client> save(Client entity) {
        String sql = "INSERT INTO client (username, name) VALUES (?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, entity.getUsername());
            stmt.setString(2, entity.getName());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Client> delete(String id) {
        Optional<Client> client = findOne(id);
        if (client.isPresent()) {
            String sql = "DELETE FROM client WHERE username = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setString(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return client;
    }

    @Override
    public Optional<Client> update(Client entity) {
        String sql = "UPDATE client SET name = ? WHERE username = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, entity.getName());
            stmt.setString(2, entity.getUsername());
            int updatedRows = stmt.executeUpdate();
            if (updatedRows > 0) {
                return Optional.empty();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }
}
