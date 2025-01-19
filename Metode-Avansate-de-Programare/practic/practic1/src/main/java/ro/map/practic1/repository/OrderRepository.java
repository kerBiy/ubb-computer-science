package ro.map.practic1.repository;

import ro.map.practic1.domain.Order;
import ro.map.practic1.domain.OrderStatus;

import java.io.*;
import java.time.LocalDateTime;
import java.util.*;

public class OrderRepository implements IRepository<Integer, Order> {
    private final String orderFile;
    private final String orderItemsFile;

    public OrderRepository(String orderFile, String orderItemsFile) {
        this.orderFile = orderFile;
        this.orderItemsFile = orderItemsFile;
    }

    private List<Order> loadFromFile() {
        Map<Integer, List<Integer>> orderItems = new HashMap<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(orderItemsFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    Integer orderId = Integer.parseInt(parts[0].trim());
                    Integer menuItemId = Integer.parseInt(parts[1].trim());
                    orderItems.computeIfAbsent(orderId, k -> new ArrayList<>()).add(menuItemId);
                }
            }
        } catch (IOException e) {
            System.err.println("Error loading order items: " + e.getMessage());
        }

        List<Order> orders = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(orderFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 4) {
                    Integer id = Integer.parseInt(parts[0].trim());
                    Integer table = Integer.parseInt(parts[1].trim());
                    LocalDateTime date = LocalDateTime.parse(parts[2].trim());
                    OrderStatus status = OrderStatus.valueOf(parts[3].trim());
                    List<Integer> menuItems = orderItems.getOrDefault(id, new ArrayList<>());
                    orders.add(new Order(id, table, menuItems, date, status));
                }
            }
        } catch (IOException e) {
            System.err.println("Error loading orders: " + e.getMessage());
        }
        return orders;
    }

    private void saveToFile(List<Order> orders) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(orderFile))) {
            for (Order order : orders) {
                writer.write(order.getId() + "," + order.getTable() + "," + order.getDate() + "," + order.getStatus());
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error saving orders: " + e.getMessage());
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(orderItemsFile))) {
            for (Order order : orders) {
                for (Integer menuItemId : order.getMenuItems()) {
                    writer.write(order.getId() + "," + menuItemId);
                    writer.newLine();
                }
            }
        } catch (IOException e) {
            System.err.println("Error saving order items: " + e.getMessage());
        }
    }

    @Override
    public Optional<Order> findOne(Integer id) {
        return loadFromFile().stream()
                .filter(order -> order.getId().equals(id))
                .findFirst();
    }

    @Override
    public Iterable<Order> findAll() {
        return loadFromFile();
    }

    @Override
    public Optional<Order> save(Order entity) {
        List<Order> orders = loadFromFile();
        if (orders.stream().anyMatch(order -> order.getId().equals(entity.getId()))) {
            return Optional.of(entity);
        }
        orders.add(entity);
        saveToFile(orders);
        return Optional.empty();
    }

    @Override
    public Optional<Order> delete(Integer id) {
        List<Order> orders = loadFromFile();
        Optional<Order> toRemove = orders.stream()
                .filter(order -> order.getId().equals(id))
                .findFirst();
        toRemove.ifPresent(orders::remove);
        saveToFile(orders);
        return toRemove;
    }

    @Override
    public Optional<Order> update(Order entity) {
        List<Order> orders = loadFromFile();
        for (int i = 0; i < orders.size(); i++) {
            if (orders.get(i).getId().equals(entity.getId())) {
                orders.set(i, entity);
                saveToFile(orders);
                return Optional.of(entity);
            }
        }
        return Optional.empty();
    }
}
