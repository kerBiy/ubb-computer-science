package ro.map.practic1.repository;

import ro.map.practic1.domain.Table;

import java.io.*;
import java.util.*;

public class TableRepository implements IRepository<Integer, Table> {
    private final String fileName;
    private final Map<Integer, Table> tableMap;

    public TableRepository(String fileName) {
        this.fileName = fileName;
        this.tableMap = new HashMap<>();
        loadFromFile();
    }

    private void loadFromFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 1) {
                    Integer id = Integer.parseInt(parts[0].trim());
                    tableMap.put(id, new Table(id));
                }
            }
        } catch (IOException e) {
            System.err.println("Error loading data from file: " + e.getMessage());
        }
    }

    private void saveToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (Table table : tableMap.values()) {
                writer.write(table.getId().toString());
                writer.newLine();
            }
        } catch (IOException e) {
            System.err.println("Error saving data to file: " + e.getMessage());
        }
    }

    @Override
    public Optional<Table> findOne(Integer id) {
        return Optional.ofNullable(tableMap.get(id));
    }

    @Override
    public Iterable<Table> findAll() {
        return tableMap.values();
    }

    @Override
    public Optional<Table> save(Table entity) {
        if (tableMap.containsKey(entity.getId())) {
            return Optional.of(entity);
        }
        tableMap.put(entity.getId(), entity);
        saveToFile();
        return Optional.empty();
    }

    @Override
    public Optional<Table> delete(Integer id) {
        Table removed = tableMap.remove(id);
        if (removed != null) {
            saveToFile();
        }
        return Optional.ofNullable(removed);
    }

    @Override
    public Optional<Table> update(Table entity) {
        if (!tableMap.containsKey(entity.getId())) {
            return Optional.empty();
        }
        tableMap.put(entity.getId(), entity);
        saveToFile();
        return Optional.of(entity);
    }
}
