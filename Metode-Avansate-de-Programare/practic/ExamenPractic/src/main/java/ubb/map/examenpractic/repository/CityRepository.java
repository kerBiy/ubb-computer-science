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
}
