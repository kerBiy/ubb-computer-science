package ubb.map.practic2023v1.repository;

import ubb.map.practic2023v1.domain.Hotel;
import ubb.map.practic2023v1.domain.Type;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class HotelRepository implements IRepository<Double, Hotel> {
    private final Connection connection;

    public HotelRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Hotel> findOne(Double id) {
        String sql = "SELECT * FROM hotel WHERE hotel_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new Hotel(
                        rs.getDouble("hotel_id"),
                        rs.getDouble("location_id"),
                        rs.getString("hotel_name"),
                        rs.getInt("no_rooms"),
                        rs.getDouble("price_per_night"),
                        Type.valueOf(rs.getString("type"))
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Hotel> findAll() {
        String sql = "SELECT * FROM hotel";
        ArrayList<Hotel> hotels = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                hotels.add(new Hotel(
                        rs.getDouble("hotel_id"),
                        rs.getDouble("location_id"),
                        rs.getString("hotel_name"),
                        rs.getInt("no_rooms"),
                        rs.getDouble("price_per_night"),
                        Type.valueOf(rs.getString("type"))
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return hotels;
    }

    @Override
    public Optional<Hotel> save(Hotel entity) {
        String sql = "INSERT INTO hotel (hotel_id, location_id, hotel_name, no_rooms, price_per_night, type) VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getId());
            stmt.setDouble(2, entity.getLocationId());
            stmt.setString(3, entity.getHotelName());
            stmt.setInt(4, entity.getNoRooms());
            stmt.setDouble(5, entity.getPricePerNight());
            stmt.setString(6, entity.getType().name());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Hotel> delete(Double id) {
        Optional<Hotel> hotel = findOne(id);
        if (hotel.isPresent()) {
            String sql = "DELETE FROM hotel WHERE hotel_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setDouble(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return hotel;
    }

    @Override
    public Optional<Hotel> update(Hotel entity) {
        String sql = "UPDATE hotel SET location_id = ?, hotel_name = ?, no_rooms = ?, price_per_night = ?, type = ? WHERE hotel_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getLocationId());
            stmt.setString(2, entity.getHotelName());
            stmt.setInt(3, entity.getNoRooms());
            stmt.setDouble(4, entity.getPricePerNight());
            stmt.setString(5, entity.getType().name());
            stmt.setDouble(6, entity.getId());
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
