package ro.map.practic1.repository;

import ro.map.practic1.domain.MenuItem;

import java.sql.*;
import java.util.*;

public class MenuItemRepository implements IRepository<Integer, MenuItem> {
    private final Connection connection;

    public MenuItemRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<MenuItem> findOne(Integer id) {
        String query = "SELECT * FROM menu_items WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return Optional.of(new MenuItem(
                        resultSet.getInt("id"),
                        resultSet.getString("category"),
                        resultSet.getString("item"),
                        resultSet.getFloat("price"),
                        resultSet.getString("currency")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<MenuItem> findAll() {
        List<MenuItem> menuItems = new ArrayList<>();
        String query = "SELECT * FROM menu_items";
        try (PreparedStatement statement = connection.prepareStatement(query);
             ResultSet resultSet = statement.executeQuery()) {
            while (resultSet.next()) {
                menuItems.add(new MenuItem(
                        resultSet.getInt("id"),
                        resultSet.getString("category"),
                        resultSet.getString("item"),
                        resultSet.getFloat("price"),
                        resultSet.getString("currency")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return menuItems;
    }

    @Override
    public Optional<MenuItem> save(MenuItem entity) {
        String query = "INSERT INTO menu_items (category, item, price, currency) VALUES (?, ?, ?, ?)";
        try (PreparedStatement statement = connection.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)) {
            statement.setString(1, entity.getCategory());
            statement.setString(2, entity.getItem());
            statement.setFloat(3, entity.getPrice());
            statement.setString(4, entity.getCurrency());
            statement.executeUpdate();

            ResultSet keys = statement.getGeneratedKeys();
            if (keys.next()) {
                entity.setId(keys.getInt(1));
                return Optional.empty();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<MenuItem> delete(Integer id) {
        Optional<MenuItem> menuItem = findOne(id);
        if (menuItem.isPresent()) {
            String query = "DELETE FROM menu_items WHERE id = ?";
            try (PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setInt(1, id);
                statement.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return menuItem;
    }

    @Override
    public Optional<MenuItem> update(MenuItem entity) {
        String query = "UPDATE menu_items SET category = ?, item = ?, price = ?, currency = ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, entity.getCategory());
            statement.setString(2, entity.getItem());
            statement.setFloat(3, entity.getPrice());
            statement.setString(4, entity.getCurrency());
            statement.setInt(5, entity.getId());
            int rows = statement.executeUpdate();
            if (rows > 0) {
                return Optional.empty();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }
}
