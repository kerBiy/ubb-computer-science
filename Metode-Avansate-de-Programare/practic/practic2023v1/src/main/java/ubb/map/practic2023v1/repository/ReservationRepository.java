package ubb.map.practic2023v1.repository;

import ubb.map.practic2023v1.domain.Reservation;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class ReservationRepository implements IRepository<Double, Reservation> {
    private final Connection connection;

    public ReservationRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Reservation> findOne(Double id) {
        String sql = "SELECT * FROM reservation WHERE reservation_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Reservation(
                        rs.getDouble("reservation_id"),
                        rs.getDouble("client_id"),
                        rs.getDouble("hotel_id"),
                        rs.getDate("start_date").toLocalDate(),
                        rs.getInt("no_nights")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Reservation> findAll() {
        String sql = "SELECT * FROM reservation";
        ArrayList<Reservation> reservations = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                reservations.add(new Reservation(
                        rs.getDouble("reservation_id"),
                        rs.getDouble("client_id"),
                        rs.getDouble("hotel_id"),
                        rs.getDate("start_date").toLocalDate(),
                        rs.getInt("no_nights")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return reservations;
    }

    @Override
    public Optional<Reservation> save(Reservation entity) {
        String sql = "INSERT INTO reservation (reservation_id, client_id, hotel_id, start_date, no_nights) VALUES (?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getId());
            stmt.setDouble(2, entity.getClientId());
            stmt.setDouble(3, entity.getHotelId());
            stmt.setDate(4, Date.valueOf(entity.getStartDate()));
            stmt.setInt(5, entity.getNoNights());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Reservation> delete(Double id) {
        Optional<Reservation> reservation = findOne(id);
        if (reservation.isPresent()) {
            String sql = "DELETE FROM reservation WHERE reservation_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setDouble(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return reservation;
    }

    @Override
    public Optional<Reservation> update(Reservation entity) {
        String sql = "UPDATE reservation SET client_id = ?, hotel_id = ?, start_date = ?, no_nights = ? WHERE reservation_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getClientId());
            stmt.setDouble(2, entity.getHotelId());
            stmt.setDate(3, Date.valueOf(entity.getStartDate()));
            stmt.setInt(4, entity.getNoNights());
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

    public Double getLastReservationId() {
        String sql = "SELECT MAX(reservation_id) FROM reservation";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return rs.getDouble(1);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return 0.0; // Dacă nu există nicio rezervare, începe de la 0
    }
}