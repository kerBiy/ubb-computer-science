package test;

import domain.Friendship;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import repository.FriendshipRepositoryFile;
import validation.Validator;

import java.io.File;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;

public class FriendshipRepositoryFileTest {
    private FriendshipRepositoryFile friendshipRepo;
    private final String filePath = "database/test_friendships.csv";
    private final File testFile = new File(filePath);

    @BeforeEach
    public void setup() {
        Validator validator = new Validator();
        friendshipRepo = new FriendshipRepositoryFile(validator, filePath);
    }

    @AfterEach
    public void tearDown() {
        if (testFile.exists()) {
            testFile.delete();
        }
    }

    @AfterAll
    public static void message() {
        System.out.println("FriendshipRepositoryFile tests ran successfully");
    }

    @Test
    public void testAddFriendship() {
        Friendship friendship = new Friendship(1L, 2L);
        friendshipRepo.save(friendship);

        Optional<Friendship> result = friendshipRepo.findOne("1-2");
        assertTrue(result.isPresent());
        assertEquals(friendship, result.get());
    }

    @Test
    public void testRemoveFriendship() {
        Friendship friendship = new Friendship(3L, 4L);
        friendshipRepo.save(friendship);

        friendshipRepo.delete("3-4");
        assertTrue(friendshipRepo.findOne("3-4").isEmpty());
    }
}