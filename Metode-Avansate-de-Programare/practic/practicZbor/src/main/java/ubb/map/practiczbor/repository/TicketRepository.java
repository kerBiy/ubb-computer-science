package ubb.map.practiczbor.repository;

import ubb.map.practiczbor.domain.Ticket;
import javafx.util.Pair;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class TicketRepository implements IRepository<Pair<String, Long>, Ticket> {
    private final Connection connection;

    public TicketRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Ticket> findOne(Pair<String, Long> id) {
        String sql = "SELECT * FROM ticket WHERE username = ? AND flight_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, id.getKey());
            stmt.setLong(2, id.getValue());
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Ticket(
                        rs.getString("username"),
                        rs.getLong("flight_id"),
                        rs.getTimestamp("purchase_time").toLocalDateTime()
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Ticket> findAll() {
        String sql = "SELECT * FROM ticket";
        ArrayList<Ticket> tickets = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                tickets.add(new Ticket(
                        rs.getString("username"),
                        rs.getLong("flight_id"),
                        rs.getTimestamp("purchase_time").toLocalDateTime()
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return tickets;
    }

    @Override
    public Optional<Ticket> save(Ticket entity) {
        String sql = "INSERT INTO ticket (username, flight_id, purchase_time) VALUES (?, ?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, entity.getUsername());
            stmt.setLong(2, entity.getFlightId());
            stmt.setTimestamp(3, Timestamp.valueOf(entity.getPurchaseTime()));
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Ticket> delete(Pair<String, Long> id) {
        Optional<Ticket> ticket = findOne(id);
        if (ticket.isPresent()) {
            String sql = "DELETE FROM ticket WHERE username = ? AND flight_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setString(1, id.getKey());
                stmt.setLong(2, id.getValue());
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return ticket;
    }

    @Override
    public Optional<Ticket> update(Ticket entity) {
        String sql = "UPDATE ticket SET purchase_time = ? WHERE username = ? AND flight_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setTimestamp(1, Timestamp.valueOf(entity.getPurchaseTime()));
            stmt.setString(2, entity.getUsername());
            stmt.setLong(3, entity.getFlightId());
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
