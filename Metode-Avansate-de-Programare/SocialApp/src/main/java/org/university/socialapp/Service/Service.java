package org.university.socialapp.Service;

import org.university.socialapp.Domain.*;
import org.university.socialapp.Repository.ConversationRepository;
import org.university.socialapp.Repository.UserRepository;
import org.university.socialapp.Repository.FriendshipRepository;
import org.university.socialapp.Utils.Observable;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.time.LocalDateTime;
import java.util.*;

public class Service extends Observable {
    private UserRepository userRepo;
    private FriendshipRepository friendshipRepo;
    private ConversationRepository conversationRepo;

    public Service(UserRepository userRepository, FriendshipRepository friendshipRepository,
                   ConversationRepository conversationRepository) {
        this.userRepo = userRepository;
        this.friendshipRepo = friendshipRepository;
        this.conversationRepo = conversationRepository;
    }

    public List<User> getUsers() {
        return userRepo.findAll();
    }

    public User getUser(String name) {
        return userRepo.findOne(name).get();
    }

    public User addUser(String name, String password) {
        User user = new User(name, hashPassword(password));

        Optional<User> savedUser = userRepo.save(user);
        if (savedUser.isPresent()) {
            throw new ServiceException("User with this ID already exists");
        }

        notifyObservers();
        return user;
    }

    public User removeUser(String name) {
        Optional<User> user = userRepo.findOne(name);
        if (user.isEmpty()) {
            throw new ServiceException("User not found");
        }

        userRepo.delete(name);
        notifyObservers();
        return user.get();
    }

    public boolean verifyLogin(String username, String password) {
        Optional<User> user = userRepo.findOne(username);
        return user.filter(value -> Objects.equals(value.getPassword(), hashPassword(password))).isPresent();
    }

    public List<User> getFriendships(String username, String status) {
        var friendships = friendshipRepo.findAll();
        List<User> output = new ArrayList<>();

        for (var friendship : friendships) {
            if (Objects.equals(friendship.getUser1(), username) && friendship.getStatus().equals(status)) {
                output.add(userRepo.findOne(friendship.getUser2()).get());
            }
        }

        return output;
    }

    public Friendship getFriendship(String user1, String user2) {
        return friendshipRepo.findOne(user1 + "-" + user2).orElse(null);

    }

    public Friendship addFriendship(String user1Id, String user2Id) {
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

        Friendship friendship = new Friendship(user1.get(), user2.get(), "pending", LocalDateTime.now());
        friendshipRepo.save(friendship);
        notifyObservers();
        return friendship;
    }

    public Friendship removeFriendship(String user1Id, String user2Id) {
        String friendshipId = user1Id + "-" + user2Id;
        Optional<Friendship> friendship = friendshipRepo.findOne(friendshipId);

        if (friendship.isEmpty()) {
            throw new ServiceException("Friendship not found");
        }

        friendshipRepo.delete(friendshipId);
        notifyObservers();
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

        List<String> LongestPathIds = graph.findLongestPathInLargestComponent();
        List<User> largestCommunity = new ArrayList<>();

        LongestPathIds.forEach(userId -> userRepo.findOne(userId).ifPresent(largestCommunity::add));

        return largestCommunity;
    }

    public boolean userExists(String name) {
        Optional<User> user = userRepo.findOne(name);
        return user.isPresent();
    }

    public List<User> getReceivedFriendRequests(String username) {
        var friendships = friendshipRepo.findAll();
        List<User> output = new ArrayList<>();

        for (var friendship : friendships) {
            if (Objects.equals(friendship.getUser2(), username) && friendship.getStatus().equals("pending")) {
                output.add(userRepo.findOne(friendship.getUser1()).get());
            }
        }

        return output;
    }

    public void respondToFriendship(String user1, String user2) {
        friendshipRepo.delete(user2 + "-" + user1);
        friendshipRepo.save(new Friendship(user1, user2, "accepted", LocalDateTime.now()));
        friendshipRepo.save(new Friendship(user2, user1, "accepted", LocalDateTime.now()));
        notifyObservers();
    }

    public void sendMessage(Long conversationId, String sender, String text) {
        Optional<Conversation> conversationOpt = conversationRepo.findOne(conversationId);
        if (conversationOpt.isEmpty()) {
            throw new IllegalArgumentException("Conversation not found with ID: " + conversationId);
        }

        Conversation conversation = conversationOpt.get();

        Message message = new Message(null, text, sender, conversation, LocalDateTime.now());
        conversation.addMessage(message);

        conversationRepo.save(conversation);
        notifyObservers();
    }

    public Conversation getOrCreateConversation(String user1, String user2) {
        List<Conversation> conversations = conversationRepo.findAll();

        for (Conversation conversation : conversations) {
            List<String> members = conversation.getMembers();
            if (members.contains(user1) && members.contains(user2) && members.size() == 2) {
                return conversation;
            }
        }

        List<String> members = new ArrayList<>();
        members.add(user1);
        members.add(user2);

        Conversation newConversation = new Conversation(null, members, new ArrayList<>());
        return conversationRepo.save(newConversation).orElseThrow(() -> new RuntimeException("Failed to create new conversation"));
    }

    public static String hashPassword(String password) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(password.getBytes());
            byte[] digest = md.digest();
            return Base64.getEncoder().encodeToString(digest);
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }
}