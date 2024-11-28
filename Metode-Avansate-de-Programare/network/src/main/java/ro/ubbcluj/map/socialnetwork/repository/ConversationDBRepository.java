package ro.ubbcluj.map.socialnetwork.repository;

import ro.ubbcluj.map.socialnetwork.domain.Conversation;
import ro.ubbcluj.map.socialnetwork.domain.Message;
import ro.ubbcluj.map.socialnetwork.domain.Utilizator;
import ro.ubbcluj.map.socialnetwork.domain.validators.ConversationValidator;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ConversationDBRepository implements Repository<Long, Conversation> {

    private final ConversationValidator validator;

    private Connection connection;

    public ConversationDBRepository(ConversationValidator validator, String url, String username, String password) {
        this.validator = validator;
        try {
            connection = DriverManager.getConnection(url, username, password);
        }
        catch (SQLException e)
        {
            throw new RuntimeException(e);
        }
    }


    @Override
    public Optional<Conversation> findOne(Long id) {
        try (PreparedStatement statement = connection.prepareStatement("SELECT * FROM conversations WHERE id=?")) {

            statement.setInt(1, Math.toIntExact(id));
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {

                    Long idSender = resultSet.getLong("sender");
                    Long idReceiver = resultSet.getLong("receiver");
                    Long idMessage = resultSet.getLong("message");
                    Timestamp date = resultSet.getTimestamp("date");
                    Long idReply = resultSet.getLong("idReply");

                    Utilizator sender = new Utilizator(null, null, null);
                    sender.setId(idSender);

                    Utilizator receiver = new Utilizator(null, null, null);
                    receiver.setId(idReceiver);

                    Message message = findMessage(idMessage).get();
                    Conversation conversation = new Conversation(sender, receiver, message);
                    conversation.setId(id);
                    conversation.setDate(date.toLocalDateTime());
                    conversation.setIdReply(idReply);

                    return Optional.of(conversation);
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }



    @Override
    public Iterable<Conversation> findAll() {
        List<Conversation> conversations = new ArrayList<>();

        try (Statement statement = connection.createStatement()) {

            try (ResultSet resultSet = statement.executeQuery("SELECT * FROM conversations")) {

                while (resultSet.next()) {
                    Long id = resultSet.getLong("id");
                    Long idSender = resultSet.getLong("sender");
                    Long idReceiver = resultSet.getLong("receiver");
                    Long idMessage = resultSet.getLong("message");
                    Timestamp date = resultSet.getTimestamp("date");
                    Long idReply = resultSet.getLong("idReply");

                    Utilizator sender = new Utilizator(null, null, null);
                    sender.setId(idSender);

                    Utilizator receiver = new Utilizator(null, null, null);
                    receiver.setId(idReceiver);

                    Message message = findMessage(idMessage).get();
                    Conversation conversation = new Conversation(sender, receiver, message);
                    conversation.setId(id);
                    conversation.setDate(date.toLocalDateTime());
                    conversation.setIdReply(idReply);

                    conversations.add(conversation);
                }

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return conversations;
    }

    public Iterable<Message> findAllMessages() {
        List<Message> messages= new ArrayList<>();

        try (Statement statement = connection.createStatement()) {

            try (ResultSet resultSet = statement.executeQuery("SELECT * FROM messages")) {

                while (resultSet.next()) {
                    String text = resultSet.getString("text");
                    Long id = resultSet.getLong("id");

                    Message message = new Message(text);
                    message.setId(id);

                    messages.add(message);
                }

            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return messages;
    }

    private Optional<Message> existMessage(String text){
        try (PreparedStatement statement = connection.prepareStatement("SELECT * FROM messages WHERE text=?")) {

            statement.setString(1, text);
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                   Long idMessage = resultSet.getLong("id");

                    Message message = new Message(text);
                    message.setId(idMessage);

                    return Optional.of(message);
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }
    public Optional<Message> findMessage(Long idMessage){
        try (PreparedStatement statement = connection.prepareStatement("SELECT * FROM messages WHERE id=?")) {

            statement.setInt(1, Math.toIntExact(idMessage));
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                    String text = resultSet.getString("text");

                    Message message = new Message(text);
                    message.setId(idMessage);

                    return Optional.of(message);
                }
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return Optional.empty();
    }

    @Override
    public Optional<Conversation> save(Conversation entity) {

//        System.out.println(entity.getId());
//        System.out.println(entity.getSender());
//        System.out.println(entity.getReceiver());
//        System.out.println(entity.getDate());
//        System.out.println(entity.getMessage().getId());
//        System.out.println(entity.getMessage().getText());
//        System.out.println(entity.getIdReply());
        if (entity == null)
            throw new IllegalArgumentException("entity must be not null");

        validator.validate(entity);

        try{
            if( existMessage(entity.getMessage().getText()).isEmpty() ){
                saveMessage(entity.getMessage());
            }
            else{
                entity.getMessage().setId(existMessage(entity.getMessage().getText()).get().getId());
            }
            saveConversation(entity);
            return Optional.of(entity);
        }catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    private void saveMessage(Message message){
        try (PreparedStatement messageStatement = connection.prepareStatement("insert into messages(text, id) values (?,?)")) {
            messageStatement.setString(1, message.getText());
            messageStatement.setLong(2, message.getId());
            messageStatement.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

    private void saveConversation(Conversation entity){
        try (PreparedStatement statement = connection.prepareStatement("insert into conversations(id, sender, receiver, message, date, idreply) values (?,?,?,?,?,?)")) {
            statement.setLong(1, entity.getId());
            statement.setLong(2, entity.getSender().getId());
            statement.setLong(3, entity.getReceiver().getId());
            statement.setLong(4, entity.getMessage().getId());
            statement.setTimestamp(5, Timestamp.valueOf(entity.getDate()));
            if (entity.getIdReply() != 0)
                statement.setLong(6, entity.getIdReply());
            else {
                statement.setNull(6, Types.BIGINT);
            }
            statement.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

        @Override
        public Optional<Conversation> delete(Long id) {
            return Optional.empty();
    }


        @Override
        public Optional<Conversation> update(Conversation entity) {
            return Optional.empty();
    }


}
