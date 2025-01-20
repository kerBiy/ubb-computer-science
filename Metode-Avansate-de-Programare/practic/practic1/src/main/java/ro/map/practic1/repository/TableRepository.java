package ro.map.practic1.repository;

import ro.map.practic1.domain.Table;

import java.sql.*;
import java.util.*;

public class TableRepository implements IRepository<Integer, Table> {
    private final Connection connection;

    public TableRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Table> findOne(Integer id) {
        String query = "SELECT * FROM tables WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return Optional.of(new Table(resultSet.getInt("id")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Table> findAll() {
        List<Table> tables = new ArrayList<>();
        String query = "SELECT * FROM tables";
        try (PreparedStatement statement = connection.prepareStatement(query);
             ResultSet resultSet = statement.executeQuery()) {
            while (resultSet.next()) {
                tables.add(new Table(resultSet.getInt("id")));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return tables;
    }

    @Override
    public Optional<Table> save(Table entity) {
        String query = "INSERT INTO tables (id) VALUES (?)";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, entity.getId());
            statement.executeUpdate();
            return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Table> delete(Integer id) {
        Optional<Table> table = findOne(id);
        if (table.isPresent()) {
            String query = "DELETE FROM tables WHERE id = ?";
            try (PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setInt(1, id);
                statement.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return table;
    }

    @Override
    public Optional<Table> update(Table entity) {
        if (findOne(entity.getId()).isPresent()) {
            String query = "UPDATE tables SET id = ? WHERE id = ?";
            try (PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setInt(1, entity.getId());
                statement.setInt(2, entity.getId());
                statement.executeUpdate();
                return Optional.empty();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return Optional.of(entity);
    }
}
