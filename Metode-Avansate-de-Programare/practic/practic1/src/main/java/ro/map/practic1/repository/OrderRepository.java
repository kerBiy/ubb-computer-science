package ro.map.practic1.repository;

import ro.map.practic1.domain.Order;
import ro.map.practic1.domain.OrderStatus;

import java.sql.*;
import java.util.*;

public class OrderRepository implements IRepository<Integer, Order> {
    private final Connection connection;

    public OrderRepository(Connection connection) {
        this.connection = connection;
    }

    @Override
    public Optional<Order> findOne(Integer id) {
        String query = "SELECT * FROM orders WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                return Optional.of(new Order(
                        resultSet.getInt("id"),
                        resultSet.getInt("table_id"),
                        findOrderItems(resultSet.getInt("id")),
                        resultSet.getTimestamp("date").toLocalDateTime(),
                        OrderStatus.valueOf(resultSet.getString("status"))
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Order> findAll() {
        List<Order> orders = new ArrayList<>();
        String query = "SELECT * FROM orders";
        try (PreparedStatement statement = connection.prepareStatement(query);
             ResultSet resultSet = statement.executeQuery()) {
            while (resultSet.next()) {
                orders.add(new Order(
                        resultSet.getInt("id"),
                        resultSet.getInt("table_id"),
                        findOrderItems(resultSet.getInt("id")),
                        resultSet.getTimestamp("date").toLocalDateTime(),
                        OrderStatus.valueOf(resultSet.getString("status"))
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return orders;
    }

    @Override
    public Optional<Order> save(Order entity) {
        String query = "INSERT INTO orders (table_id, date, status) VALUES (?, ?, ?)";
        try (PreparedStatement statement = connection.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)) {
            statement.setInt(1, entity.getTable());
            statement.setTimestamp(2, Timestamp.valueOf(entity.getDate()));
            statement.setString(3, entity.getStatus().name());
            statement.executeUpdate();

            ResultSet keys = statement.getGeneratedKeys();
            if (keys.next()) {
                int orderId = keys.getInt(1);
                saveOrderItems(orderId, entity.getMenuItems());
                return Optional.empty();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Order> delete(Integer id) {
        Optional<Order> order = findOne(id);
        if (order.isPresent()) {
            String deleteItemsQuery = "DELETE FROM order_items WHERE order_id = ?";
            String deleteOrderQuery = "DELETE FROM orders WHERE id = ?";
            try (PreparedStatement deleteItemsStmt = connection.prepareStatement(deleteItemsQuery);
                 PreparedStatement deleteOrderStmt = connection.prepareStatement(deleteOrderQuery)) {
                deleteItemsStmt.setInt(1, id);
                deleteItemsStmt.executeUpdate();

                deleteOrderStmt.setInt(1, id);
                deleteOrderStmt.executeUpdate();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return order;
    }

    @Override
    public Optional<Order> update(Order entity) {
        String query = "UPDATE orders SET table_id = ?, date = ?, status = ? WHERE id = ?";
        if (findOne(entity.getId()).isPresent()) {
            try (PreparedStatement statement = connection.prepareStatement(query)) {
                statement.setInt(1, entity.getTable());
                statement.setTimestamp(2, Timestamp.valueOf(entity.getDate()));
                statement.setString(3, entity.getStatus().name());
                statement.setInt(4, entity.getId());
                statement.executeUpdate();

                saveOrderItems(entity.getId(), entity.getMenuItems());
                return Optional.empty();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return Optional.of(entity);
    }

    private List<Integer> findOrderItems(int orderId) {
        List<Integer> menuItems = new ArrayList<>();
        String query = "SELECT menu_item_id FROM order_items WHERE order_id = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, orderId);
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                menuItems.add(resultSet.getInt("menu_item_id"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return menuItems;
    }

    private void saveOrderItems(int orderId, List<Integer> menuItems) {
        String deleteQuery = "DELETE FROM order_items WHERE order_id = ?";
        String insertQuery = "INSERT INTO order_items (order_id, menu_item_id) VALUES (?, ?)";
        try (PreparedStatement deleteStmt = connection.prepareStatement(deleteQuery);
             PreparedStatement insertStmt = connection.prepareStatement(insertQuery)) {
            deleteStmt.setInt(1, orderId);
            deleteStmt.executeUpdate();

            for (Integer menuItemId : menuItems) {
                insertStmt.setInt(1, orderId);
                insertStmt.setInt(2, menuItemId);
                insertStmt.addBatch();
            }
            insertStmt.executeBatch();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
