package ubb.map.practic2023v1.repository;

import ubb.map.practic2023v1.domain.Client;
import ubb.map.practic2023v1.domain.Hobbies;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class ClientRepository implements IRepository<Double, Client> {
    private final Connection connection;

    public ClientRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Client> findOne(Double id) {
        String sql = "SELECT * FROM client WHERE client_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Client(
                        rs.getDouble("client_id"),
                        rs.getString("name"),
                        rs.getInt("fidelity_grade"),
                        rs.getInt("age"),
                        Hobbies.valueOf(rs.getString("hobbies"))
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
                        rs.getDouble("client_id"),
                        rs.getString("name"),
                        rs.getInt("fidelity_grade"),
                        rs.getInt("age"),
                        Hobbies.valueOf(rs.getString("hobbies"))
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return clients;
    }

    @Override
    public Optional<Client> save(Client entity) {
        String sql = "INSERT INTO client (client_id, name, fidelity_grade, age, hobbies) VALUES (?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getId());
            stmt.setString(2, entity.getName());
            stmt.setInt(3, entity.getFidelityGrade());
            stmt.setInt(4, entity.getAge());
            stmt.setString(5, entity.getHobbies().name());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Client> delete(Double id) {
        Optional<Client> client = findOne(id);
        if (client.isPresent()) {
            String sql = "DELETE FROM client WHERE client_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setDouble(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return client;
    }

    @Override
    public Optional<Client> update(Client entity) {
        String sql = "UPDATE client SET name = ?, fidelity_grade = ?, age = ?, hobbies = ? WHERE client_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, entity.getName());
            stmt.setInt(2, entity.getFidelityGrade());
            stmt.setInt(3, entity.getAge());
            stmt.setString(4, entity.getHobbies().name());
            stmt.setDouble(5, entity.getId());
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