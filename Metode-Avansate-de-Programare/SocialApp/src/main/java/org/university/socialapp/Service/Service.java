package org.university.socialapp.Service;

import org.university.socialapp.Domain.Graph;
import org.university.socialapp.Domain.User;
import org.university.socialapp.Domain.Friendship;
import org.university.socialapp.Repository.UserRepository;
import org.university.socialapp.Repository.FriendshipRepository;

import java.util.List;
import java.util.ArrayList;
import java.util.Optional;

public class Service {
    private UserRepository userRepo;
    private FriendshipRepository friendshipRepo;

    public Service(UserRepository userRepository, FriendshipRepository friendshipRepository) {
        this.userRepo = userRepository;
        this.friendshipRepo = friendshipRepository;
    }

    public List<User> getUsers() {
        return userRepo.findAll();
    }

    public User addUser(Long id, String name, String password) {
        User user = new User(id, name, password);

        Optional<User> savedUser = userRepo.save(user);
        if (savedUser.isPresent()) {
            throw new ServiceException("User with this ID already exists");
        }

        return user;
    }

    public User removeUser(Long id) {
        Optional<User> user = userRepo.findOne(id);
        if (user.isEmpty()) {
            throw new ServiceException("User not found");
        }

        userRepo.delete(id);
        return user.get();
    }

    public Friendship addFriendship(Long user1Id, Long user2Id) {
        Optional<User> user1 = userRepo.findOne(user1Id);
        Optional<User> user2 = userRepo.findOne(user2Id);

        if (user1.isEmpty() || user2.isEmpty()) {
            throw new ServiceException("One or both users not found");
        }

        String friendshipId = user1Id + "-" + user2Id;

        Optional<Friendship> existingFriendship = friendshipRepo.findOne(friendshipId);
        if (existingFriendship.isPresent()) {
            throw new ServiceException("Friendship already exists");
        }

        Friendship friendship = new Friendship(user1.get(), user2.get());
        friendshipRepo.save(friendship);
        return friendship;
    }

    public Friendship removeFriendship(Long user1Id, Long user2Id) {
        String friendshipId = user1Id + "-" + user2Id;
        Optional<Friendship> friendship = friendshipRepo.findOne(friendshipId);

        if (friendship.isEmpty()) {
            throw new ServiceException("Friendship not found");
        }

        friendshipRepo.delete(friendshipId);
        return friendship.get();
    }

    public int getCommunityNumber() {
        List<User> users = userRepo.findAll();
        List<Friendship> friendships = friendshipRepo.findAll();

        Graph graph = new Graph(users.size(), friendships);
        return graph.findStronglyConnectedComponents();
    }

    public List<User> getLargestCommunity() {
        List<User> users = userRepo.findAll();
        List<Friendship> friendships = friendshipRepo.findAll();

        Graph graph = new Graph(users.size(), friendships);

        List<Long> longestPathIds = graph.findLongestPathInLargestComponent();
        List<User> largestCommunity = new ArrayList<>();

        longestPathIds.forEach(userId -> userRepo.findOne(userId).ifPresent(largestCommunity::add));

        return largestCommunity;
    }
}