package ubb.map.examenpractic.repository;

import ubb.map.examenpractic.domain.City;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class CityRepository implements IRepository<String, City> {
    private final Connection connection;

    public CityRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<City> findOne(String id) {
        String query = "SELECT * FROM City WHERE id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(query)) {
            stmt.setString(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new City(rs.getString("id"), rs.getString("name")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<City> findAll() {
        List<City> cities = new ArrayList<>();
        String query = "SELECT * FROM City";
        try (Statement stmt = connection.createStatement(); ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                cities.add(new City(rs.getString("id"), rs.getString("name")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return cities;
    }

    @Override
    public Optional<City> save(City entity) {
        String query = "INSERT INTO City (id, name) VALUES (?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(query)) {
            stmt.setString(1, entity.getId());
            stmt.setString(2, entity.getName());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<City> delete(String id) {
        Optional<City> city = findOne(id);
        if (city.isPresent()) {
            String query = "DELETE FROM City WHERE id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(query)) {
                stmt.setString(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return city;
    }

    @Override
    public Optional<City> update(City entity) {
        String query = "UPDATE City SET name = ? WHERE id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(query)) {
            stmt.setString(1, entity.getName());
            stmt.setString(2, entity.getId());
            int rowsUpdated = stmt.executeUpdate();
            if (rowsUpdated > 0) {
                return Optional.empty();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }
}
