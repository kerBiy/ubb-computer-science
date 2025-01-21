package ubb.map.practicajutor.repository;

import ubb.map.practicajutor.domain.Nevoie;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class NevoieRepository implements IRepository<Long, Nevoie> {
    private final Connection connection;

    public NevoieRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Nevoie> findOne(Long id) {
        String query = "SELECT * FROM nevoie WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return Optional.of(mapResultSetToEntity(resultSet));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Nevoie> findAll() {
        String query = "SELECT * FROM nevoie";
        List<Nevoie> nevoi = new ArrayList<>();
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                nevoi.add(mapResultSetToEntity(resultSet));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return nevoi;
    }

    @Override
    public Optional<Nevoie> save(Nevoie entity) {
        String query = "INSERT INTO nevoie (titlu, descriere, deadline, om_in_nevoie, om_salvator, status) VALUES (?, ?, ?, ?, ?, ?) RETURNING id";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, entity.getTitlu());
            statement.setString(2, entity.getDescriere());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getDeadline()));
            statement.setLong(4, entity.getOmInNevoie());
            statement.setObject(5, entity.getOmSalvator());
            statement.setString(6, entity.getStatus());

            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                entity.setId(resultSet.getLong("id"));
                return Optional.of(entity);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Optional<Nevoie> delete(Long id) {
        Optional<Nevoie> nevoie = findOne(id);
        if (nevoie.isPresent()) {
            String query = "DELETE FROM nevoie WHERE id = ?";
            try (PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setLong(1, id);
                statement.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return nevoie;
    }

    @Override
    public Optional<Nevoie> update(Nevoie entity) {
        String query = "UPDATE nevoie SET titlu = ?, descriere = ?, deadline = ?, om_in_nevoie = ?, om_salvator = ?, status = ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, entity.getTitlu());
            statement.setString(2, entity.getDescriere());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getDeadline()));
            statement.setLong(4, entity.getOmInNevoie());
            statement.setObject(5, entity.getOmSalvator());
            statement.setString(6, entity.getStatus());
            statement.setLong(7, entity.getId());
            statement.executeUpdate();
            return Optional.of(entity);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    private Nevoie mapResultSetToEntity(ResultSet resultSet) throws SQLException {
        return new Nevoie(
                resultSet.getLong("id"),
                resultSet.getString("titlu"),
                resultSet.getString("descriere"),
                resultSet.getTimestamp("deadline").toLocalDateTime(),
                resultSet.getLong("om_in_nevoie"),
                resultSet.getObject("om_salvator", Long.class),
                resultSet.getString("status")
        );
    }
}

