package ubb.map.examenpractic.repository;

import ubb.map.examenpractic.domain.TrainStation;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class TrainStationRepository implements IRepository<String, TrainStation> {
    private final Connection connection;

    public TrainStationRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<TrainStation> findOne(String id) {
        String query = "SELECT * FROM TrainStation WHERE id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(query)) {
            stmt.setString(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new TrainStation(
                        rs.getString("id"),
                        rs.getString("departure_city_id"),
                        rs.getString("destination_city_id")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<TrainStation> findAll() {
        List<TrainStation> stations = new ArrayList<>();
        String query = "SELECT * FROM TrainStation";
        try (Statement stmt = connection.createStatement(); ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                stations.add(new TrainStation(
                        rs.getString("id"),
                        rs.getString("departure_city_id"),
                        rs.getString("destination_city_id")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return stations;
    }
}

