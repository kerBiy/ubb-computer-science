package repository;

import domain.Friendship;
import validation.Validator;

import java.io.*;
import java.util.Optional;

public class FriendshipRepositoryFile extends FriendshipRepository {
    private String filePath;

    public FriendshipRepositoryFile(Validator validator, String filePath) {
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
                if (attributes.length >= 2) {
                    Long idUser1 = Long.parseLong(attributes[0].trim());
                    Long idUser2 = Long.parseLong(attributes[1].trim());

                    Friendship friendship= new Friendship(idUser1, idUser2);
                    super.save(friendship);
                }
            }
        } catch (IOException e) {
            System.out.println("Eroare la citirea fișierului CSV: " + e.getMessage());
        }
    }

    private void saveToFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            for (Friendship friendship : findAll()) {
                writer.write(friendship.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            System.out.println("Eroare la scriere in fișierului CSV: " + e.getMessage());
        }

    }

    @Override
    public Optional<Friendship> save(Friendship friendship) {
        Optional<Friendship> result = super.save(friendship);
        saveToFile();
        return result;
    }

    @Override
    public Optional<Friendship> delete(String id) {
        Optional<Friendship> result = super.delete(id);
        saveToFile();
        return result;
    }

    @Override
    public Optional<Friendship> update(Friendship friendship) {
        Optional<Friendship> result = super.update(friendship);
        saveToFile();
        return result;
    }
}
