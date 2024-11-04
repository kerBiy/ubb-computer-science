package test;

import domain.Friendship;
import domain.User;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import repository.FriendshipRepositoryFile;
import repository.UserRepositoryFile;
import service.Service;
import validation.Validator;

import java.io.File;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class ServiceTest {
    private Service service;
    private UserRepositoryFile userRepo;
    private FriendshipRepositoryFile friendshipRepo;
    private final File userFile = new File("database/test_users.csv");
    private final File friendshipFile = new File("database/test_friendships.csv");

    @BeforeEach
    public void setup() {
        Validator validator = new Validator();
        userRepo = new UserRepositoryFile(validator, userFile.getPath());
        friendshipRepo = new FriendshipRepositoryFile(validator, friendshipFile.getPath());
        service = new Service(userRepo, friendshipRepo);
    }

    @AfterEach
    public void tearDown() {
        if (userFile.exists()) {
            userFile.delete();
        }
        if (friendshipFile.exists()) {
            friendshipFile.delete();
        }
    }

    @AfterAll
    public static void message() {
        System.out.println("Service tests ran successfully");
    }

    @Test
    public void testAddUser() {
        User user = service.addUser(1L, "John Doe", "john@example.com");
        assertEquals("John Doe", user.getName());
    }

    @Test
    public void testRemoveUser() {
        service.addUser(1L, "John Doe", "john@example.com");
        User removedUser = service.removeUser(1L);

        assertEquals("John Doe", removedUser.getName());
        assertTrue(userRepo.findOne(1L).isEmpty());
    }

    @Test
    public void testAddFriendship() {
        service.addUser(1L, "John Doe", "john@example.com");
        service.addUser(2L, "Jane Doe", "jane@example.com");

        Friendship friendship = service.addFriendship(1L, 2L);
        assertNotNull(friendship);
        assertEquals(1L, friendship.getUser1());
        assertEquals(2L, friendship.getUser2());
    }

    @Test
    public void testRemoveFriendship() {
        service.addUser(1L, "John Doe", "john@example.com");
        service.addUser(2L, "Jane Doe", "jane@example.com");
        service.addFriendship(1L, 2L);

        Friendship removedFriendship = service.removeFriendship(1L, 2L);
        assertEquals(1L, removedFriendship.getUser1());
        assertEquals(2L, removedFriendship.getUser2());
        assertTrue(friendshipRepo.findOne("1-2").isEmpty());
    }

    @Test
    public void testGetCommunityNumber() {
        service.addUser(1L, "Alice", "alice@example.com");
        service.addUser(2L, "Bob", "bob@example.com");
        service.addUser(3L, "Charlie", "charlie@example.com");

        service.addFriendship(1L, 2L);
        assertEquals(1, service.getCommunityNumber());
    }

    @Test
    public void testGetLargestCommunity() {
        service.addUser(1L, "Alice", "alice@example.com");
        service.addUser(2L, "Bob", "bob@example.com");
        service.addUser(3L, "Charlie", "charlie@example.com");

        service.addFriendship(1L, 2L);
        service.addFriendship(2L, 3L);

        List<User> largestCommunity = service.getLargestCommunity();
        assertEquals(3, largestCommunity.size());
    }
}