package ubb.map.practicajutor.repository;

import ubb.map.practicajutor.domain.Persoana;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class PersoanaRepository implements IRepository<Long, Persoana> {
    private final Connection connection;

    public PersoanaRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Persoana> findOne(Long id) {
        String query = "SELECT * FROM persoana WHERE id = ?";
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
    public Iterable<Persoana> findAll() {
        String query = "SELECT * FROM persoana";
        List<Persoana> persoane = new ArrayList<>();
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                persoane.add(mapResultSetToEntity(resultSet));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return persoane;
    }

    @Override
    public Optional<Persoana> save(Persoana entity) {
        String query = "INSERT INTO persoana (nume, prenume, username, parola, oras, strada, numar_strada, telefon) VALUES (?, ?, ?, ?, ?, ?, ?, ?) RETURNING id";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, entity.getNume());
            statement.setString(2, entity.getPrenume());
            statement.setString(3, entity.getUsername());
            statement.setString(4, entity.getParola());
            statement.setString(5, entity.getOras());
            statement.setString(6, entity.getStrada());
            statement.setString(7, entity.getNumarStrada());
            statement.setString(8, entity.getTelefon());

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
    public Optional<Persoana> delete(Long id) {
        Optional<Persoana> persoana = findOne(id);
        if (persoana.isPresent()) {
            String query = "DELETE FROM persoana WHERE id = ?";
            try (PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setLong(1, id);
                statement.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return persoana;
    }

    @Override
    public Optional<Persoana> update(Persoana entity) {
        String query = "UPDATE persoana SET nume = ?, prenume = ?, username = ?, parola = ?, oras = ?, strada = ?, numar_strada = ?, telefon = ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, entity.getNume());
            statement.setString(2, entity.getPrenume());
            statement.setString(3, entity.getUsername());
            statement.setString(4, entity.getParola());
            statement.setString(5, entity.getOras());
            statement.setString(6, entity.getStrada());
            statement.setString(7, entity.getNumarStrada());
            statement.setString(8, entity.getTelefon());
            statement.setLong(9, entity.getId());
            statement.executeUpdate();
            return Optional.of(entity);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    private Persoana mapResultSetToEntity(ResultSet resultSet) throws SQLException {
        return new Persoana(
                resultSet.getLong("id"),
                resultSet.getString("nume"),
                resultSet.getString("prenume"),
                resultSet.getString("username"),
                resultSet.getString("parola"),
                resultSet.getString("oras"),
                resultSet.getString("strada"),
                resultSet.getString("numar_strada"),
                resultSet.getString("telefon")
        );
    }
}
