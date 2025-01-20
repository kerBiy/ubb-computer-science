// Repository pentru clasa SpecialOffer
package ubb.map.practic2023v1.repository;

import ubb.map.practic2023v1.domain.SpecialOffer;

import java.sql.*;
import java.util.ArrayList;
import java.util.Optional;

public class SpecialOfferRepository implements IRepository<Double, SpecialOffer> {
    private final Connection connection;

    public SpecialOfferRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<SpecialOffer> findOne(Double id) {
        String sql = "SELECT * FROM special_offer WHERE special_offer_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, id);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return Optional.of(new SpecialOffer(
                        rs.getDouble("special_offer_id"),
                        rs.getDouble("hotel_id"),
                        rs.getDate("start_date"),
                        rs.getDate("end_date"),
                        rs.getInt("percents")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<SpecialOffer> findAll() {
        String sql = "SELECT * FROM special_offer";
        ArrayList<SpecialOffer> specialOffers = new ArrayList<>();
        try (Statement stmt = connection.createStatement()) {
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                specialOffers.add(new SpecialOffer(
                        rs.getDouble("special_offer_id"),
                        rs.getDouble("hotel_id"),
                        rs.getDate("start_date"),
                        rs.getDate("end_date"),
                        rs.getInt("percents")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return specialOffers;
    }

    @Override
    public Optional<SpecialOffer> save(SpecialOffer entity) {
        String sql = "INSERT INTO special_offer (special_offer_id, hotel_id, start_date, end_date, percents) VALUES (?, ?, ?, ?, ?)";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getId());
            stmt.setDouble(2, entity.getHotelId());
            stmt.setDate(3, new java.sql.Date(entity.getStartDate().getTime()));
            stmt.setDate(4, new java.sql.Date(entity.getEndDate().getTime()));
            stmt.setInt(5, entity.getPercents());
            stmt.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<SpecialOffer> delete(Double id) {
        Optional<SpecialOffer> specialOffer = findOne(id);
        if (specialOffer.isPresent()) {
            String sql = "DELETE FROM special_offer WHERE special_offer_id = ?";
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {
                stmt.setDouble(1, id);
                stmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return specialOffer;
    }

    @Override
    public Optional<SpecialOffer> update(SpecialOffer entity) {
        String sql = "UPDATE special_offer SET hotel_id = ?, start_date = ?, end_date = ?, percents = ? WHERE special_offer_id = ?";
        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setDouble(1, entity.getHotelId());
            stmt.setDate(2, new java.sql.Date(entity.getStartDate().getTime()));
            stmt.setDate(3, new java.sql.Date(entity.getEndDate().getTime()));
            stmt.setInt(4, entity.getPercents());
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
