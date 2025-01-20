package ubb.map.practiczbor.repository;

import ubb.map.practiczbor.domain.Flight;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class FlightRepository implements IRepository<Long, Flight> {
    private final Connection connection;

    public FlightRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Flight> findOne(Long id) {
        String sql = "SELECT * FROM flight WHERE flight_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setLong(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Flight(
                        rs.getLong("flight_id"),
                        rs.getString("from"),
                        rs.getString("to"),
                        rs.getTimestamp("departure_time").toLocalDateTime(),
                        rs.getTimestamp("landing_time").toLocalDateTime(),
                        rs.getInt("seats")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Flight> findAll() {
        String sql = "SELECT * FROM flight";
        ArrayList<Flight> flights = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                flights.add(new Flight(
                        rs.getLong("flight_id"),
                        rs.getString("from"),
                        rs.getString("to"),
                        rs.getTimestamp("departure_time").toLocalDateTime(),
                        rs.getTimestamp("landing_time").toLocalDateTime(),
                        rs.getInt("seats")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return flights;
    }

    @Override
    public Optional<Flight> save(Flight entity) {
        String sql = "INSERT INTO flight (flight_id, from, to, departure_time, landing_time, seats) VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setLong(1, entity.getId());
            stmt.setString(2, entity.getFrom());
            stmt.setString(3, entity.getTo());
            stmt.setTimestamp(4, Timestamp.valueOf(entity.getDepartureTime()));
            stmt.setTimestamp(5, Timestamp.valueOf(entity.getLandingTime()));
            stmt.setInt(6, entity.getSeats());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Flight> delete(Long id) {
        Optional<Flight> flight = findOne(id);
        if (flight.isPresent()) {
            String sql = "DELETE FROM flight WHERE flight_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setLong(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return flight;
    }

    @Override
    public Optional<Flight> update(Flight entity) {
        String sql = "UPDATE flight SET from = ?, to = ?, departure_time = ?, landing_time = ?, seats = ? WHERE flight_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, entity.getFrom());
            stmt.setString(2, entity.getTo());
            stmt.setTimestamp(3, Timestamp.valueOf(entity.getDepartureTime()));
            stmt.setTimestamp(4, Timestamp.valueOf(entity.getLandingTime()));
            stmt.setInt(5, entity.getSeats());
            stmt.setLong(6, entity.getId());
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
