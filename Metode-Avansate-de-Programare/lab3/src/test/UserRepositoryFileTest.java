package test;

import domain.User;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import repository.UserRepositoryFile;
import validation.Validator;

import java.io.File;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;

public class UserRepositoryFileTest {
    private UserRepositoryFile userRepo;
    private final String filePath = "database/test_users.csv";
    private final File testFile = new File(filePath);

    @BeforeEach
    public void setup() {
        Validator validator = new Validator();
        userRepo = new UserRepositoryFile(validator, filePath);
    }

    @AfterEach
    public void tearDown() {
        if (testFile.exists()) {
            testFile.delete();
        }
    }

    @AfterAll
    public static void message() {
        System.out.println("UserRepositoryFile tests ran successfully");
    }

    @Test
    public void testAddUser() {
        User user = new User(1L, "John Doe", "john@example.com");
        userRepo.save(user);

        Optional<User> result = userRepo.findOne(1L);
        assertTrue(result.isPresent());
        assertEquals(user, result.get());
    }

    @Test
    public void testRemoveUser() {
        User user = new User(2L, "Jane Doe", "jane@example.com");
        userRepo.save(user);

        userRepo.delete(2L);
        assertTrue(userRepo.findOne(2L).isEmpty());
    }

    @Test
    public void testFindAll() {
        userRepo.save(new User(3L, "Alice", "alice@example.com"));
        userRepo.save(new User(4L, "Bob", "bob@example.com"));

        assertEquals(2, userRepo.findAll().size());
    }
}