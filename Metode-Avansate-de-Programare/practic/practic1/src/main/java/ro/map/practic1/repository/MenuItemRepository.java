package ro.map.practic1.repository;

import ro.map.practic1.domain.MenuItem;

import java.io.*;
import java.util.*;

public class MenuItemRepository implements IRepository<Integer, MenuItem> {
    private final String fileName;

    public MenuItemRepository(String fileName) {
        this.fileName = fileName;
    }

    private List<MenuItem> loadFromFile() {
        List<MenuItem> items = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 5) {
                    Integer id = Integer.parseInt(parts[0].trim());
                    String category = parts[1].trim();
                    String item = parts[2].trim();
                    Float price = Float.parseFloat(parts[3].trim());
                    String currency = parts[4].trim();
                    items.add(new MenuItem(id, category, item, price, currency));
                }
            }
        } catch (IOException e) {
            System.err.println("Error loading data from file: " + e.getMessage());
        }
        return items;
    }

    private void saveToFile(List<MenuItem> items) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (MenuItem item : items) {
                writer.write(item.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error saving data to file: " + e.getMessage());
        }
    }

    @Override
    public Optional<MenuItem> findOne(Integer id) {
        return loadFromFile().stream()
                .filter(item -> item.getId().equals(id))
                .findFirst();
    }

    @Override
    public Iterable<MenuItem> findAll() {
        return loadFromFile();
    }

    @Override
    public Optional<MenuItem> save(MenuItem entity) {
        List<MenuItem> items = loadFromFile();
        if (items.stream().anyMatch(item -> item.getId().equals(entity.getId()))) {
            return Optional.of(entity);
        }
        items.add(entity);
        saveToFile(items);
        return Optional.empty();
    }

    @Override
    public Optional<MenuItem> delete(Integer id) {
        List<MenuItem> items = loadFromFile();
        Optional<MenuItem> toRemove = items.stream()
                .filter(item -> item.getId().equals(id))
                .findFirst();
        toRemove.ifPresent(items::remove);
        saveToFile(items);
        return toRemove;
    }

    @Override
    public Optional<MenuItem> update(MenuItem entity) {
        List<MenuItem> items = loadFromFile();
        for (int i = 0; i < items.size(); i++) {
            if (items.get(i).getId().equals(entity.getId())) {
                items.set(i, entity);
                saveToFile(items);
                return Optional.of(entity);
            }
        }
        return Optional.empty();
    }
}