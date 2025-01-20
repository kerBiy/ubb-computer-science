package ubb.map.practic2023v1.repository;

import ubb.map.practic2023v1.domain.Location;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class LocationRepository implements IRepository<Double, Location> {
    private final Connection connection;

    public LocationRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Location> findOne(Double id) {
        String sql = "SELECT * FROM location WHERE location_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Location(
                        rs.getDouble("location_id"),
                        rs.getString("location_name")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Location> findAll() {
        String sql = "SELECT * FROM location";
        ArrayList<Location> locations = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                locations.add(new Location(
                        rs.getDouble("location_id"),
                        rs.getString("location_name")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return locations;
    }

    @Override
    public Optional<Location> save(Location entity) {
        String sql = "INSERT INTO location (location_id, location_name) VALUES (?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getId());
            stmt.setString(2, entity.getLocationName());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Location> delete(Double id) {
        Optional<Location> location = findOne(id);
        if (location.isPresent()) {
            String sql = "DELETE FROM location WHERE location_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setDouble(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return location;
    }

    @Override
    public Optional<Location> update(Location entity) {
        String sql = "UPDATE location SET location_name = ? WHERE location_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, entity.getLocationName());
            stmt.setDouble(2, entity.getId());
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