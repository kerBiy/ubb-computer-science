package repository;

import domain.User;
import validation.Validator;

import java.io.*;
import java.util.Optional;

public class UserRepositoryFile extends UserRepository {
    private final String filePath;

    public UserRepositoryFile(Validator validator, String filePath) {
        super(validator);
        this.filePath = filePath;
        createFileIfNotExists();
        loadFromFile();
    }

    private void createFileIfNotExists() {
        try {
            File file = new File(filePath);
            File parentDir = file.getParentFile();
            if (parentDir != null && !parentDir.exists()) {
                parentDir.mkdirs();
            }
            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (IOException e) {
            System.out.println("Error creating file or directory: " + e.getMessage());
        }
    }

    private void loadFromFile() {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] attributes = line.split(",");
                if (attributes.length >= 3) {
                    Long id = Long.parseLong(attributes[0].trim());
                    String name = attributes[1].trim();
                    String email = attributes[2].trim();

                    User user = new User(id, name, email);
                    super.save(user);
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading CSV file: " + e.getMessage());
        }
    }

    private void saveToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (User user : findAll()) {
                writer.write(user.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Error writing to CSV file: " + e.getMessage());
        }
    }

    @Override
    public Optional<User> save(User user) {
        Optional<User> result = super.save(user);
        saveToFile();
        return result;
    }

    @Override
    public Optional<User> delete(Long id) {
        Optional<User> result = super.delete(id);
        saveToFile();
        return result;
    }

    @Override
    public Optional<User> update(User user) {
        Optional<User> result = super.update(user);
        saveToFile();
        return result;
    }
}