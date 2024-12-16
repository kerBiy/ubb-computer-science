package org.university.socialapp.Repository;

import org.university.socialapp.Domain.Conversation;
import org.university.socialapp.Domain.Message;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ConversationRepository {

    private final String url;
    private final String user;
    private final String password;

    public ConversationRepository(String url, String user, String password) {
        this.url = url;
        this.user = user;
        this.password = password;
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, user, password);
    }

    public Optional<Conversation> findOne(Long conversationId) {
        String membersQuery = "SELECT user_id FROM ConversationMembers WHERE conversation_id = ?";
        String messagesQuery = "SELECT id, text, sender, date_time FROM Messages WHERE conversation_id = ?";
        List<String> members = new ArrayList<>();
        List<Message> messages = new ArrayList<>();

        try (Connection connection = getConnection()) {
            // Fetch members
            try (PreparedStatement statement = connection.prepareStatement(membersQuery)) {
                statement.setLong(1, conversationId);
                ResultSet resultSet = statement.executeQuery();
                while (resultSet.next()) {
                    members.add(resultSet.getString("user_id"));
                }
            }

            // Fetch messages
            try (PreparedStatement statement = connection.prepareStatement(messagesQuery)) {
                statement.setLong(1, conversationId);
                ResultSet resultSet = statement.executeQuery();
                while (resultSet.next()) {
                    Long id = resultSet.getLong("id");
                    String text = resultSet.getString("text");
                    String sender = resultSet.getString("sender");
                    Timestamp timestamp = resultSet.getTimestamp("date_time");
                    messages.add(new Message(id, text, sender, null, timestamp.toLocalDateTime()));
                }
            }

            if (!members.isEmpty() || !messages.isEmpty()) {
                return Optional.of(new Conversation(conversationId, members, messages));
            }
        } catch (SQLException e) {
            System.out.println("Error fetching conversation: " + e.getMessage());
        }

        return Optional.empty();
    }

    public List<Conversation> findAll() {
        List<Conversation> conversations = new ArrayList<>();
        String conversationsQuery = "SELECT id FROM Conversations";

        try (Connection connection = getConnection();
             Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(conversationsQuery)) {

            while (resultSet.next()) {
                Long conversationId = resultSet.getLong("id");
                findOne(conversationId).ifPresent(conversations::add);
            }
        } catch (SQLException e) {
            System.out.println("Error fetching all conversations: " + e.getMessage());
        }

        return conversations;
    }

    public Optional<Conversation> save(Conversation conversation) {
        if (conversation.getId() == null) {
            String insertConversationQuery = "INSERT INTO Conversations (created_at) VALUES (CURRENT_TIMESTAMP)";
            try (Connection connection = getConnection();
                 PreparedStatement statement = connection.prepareStatement(insertConversationQuery, Statement.RETURN_GENERATED_KEYS)) {

                statement.executeUpdate();
                ResultSet keys = statement.getGeneratedKeys();
                if (keys.next()) {
                    conversation.setId(keys.getLong(1));
                }
            } catch (SQLException e) {
                System.out.println("Error saving conversation: " + e.getMessage());
                return Optional.empty();
            }
        }

        Long conversationId = conversation.getId();

        // Save members
        String insertMemberQuery = "INSERT INTO ConversationMembers (conversation_id, user_id) VALUES (?, ?)";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(insertMemberQuery)) {

            for (String userId : conversation.getMembers()) {
                statement.setLong(1, conversationId);
                statement.setString(2, userId);
                statement.addBatch();
            }
            statement.executeBatch();
        } catch (SQLException e) {
            System.out.println("Error saving conversation members: " + e.getMessage());
        }

        // Delete all existing messages for the conversation
        String deleteMessagesQuery = "DELETE FROM Messages WHERE conversation_id = ?";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(deleteMessagesQuery)) {

            statement.setLong(1, conversationId);
            statement.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Error deleting old messages: " + e.getMessage());
        }

        // Save new messages
        String insertMessageQuery = "INSERT INTO Messages (text, sender, conversation_id, date_time) VALUES (?, ?, ?, ?)";
        try (Connection connection = getConnection();
             PreparedStatement statement = connection.prepareStatement(insertMessageQuery)) {

            for (Message message : conversation.getMessages()) {
                statement.setString(1, message.getText());
                statement.setString(2, message.getSender());
                statement.setLong(3, conversationId);
                statement.setTimestamp(4, Timestamp.valueOf(message.getDateTime()));
                statement.addBatch();
            }
            statement.executeBatch();
        } catch (SQLException e) {
            System.out.println("Error saving conversation messages: " + e.getMessage());
        }

        return findOne(conversationId);
    }


    public Optional<Conversation> delete(Long conversationId) {
        Optional<Conversation> conversation = findOne(conversationId);
        if (conversation.isPresent()) {
            String deleteQuery = "DELETE FROM Conversations WHERE id = ?";
            try (Connection connection = getConnection();
                 PreparedStatement statement = connection.prepareStatement(deleteQuery)) {

                statement.setLong(1, conversationId);
                statement.executeUpdate();
            } catch (SQLException e) {
                System.out.println("Error deleting conversation: " + e.getMessage());
            }
        }
        return conversation;
    }
}
