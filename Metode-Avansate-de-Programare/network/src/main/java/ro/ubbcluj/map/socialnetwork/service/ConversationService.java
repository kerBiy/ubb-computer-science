package ro.ubbcluj.map.socialnetwork.service;

import ro.ubbcluj.map.socialnetwork.domain.Conversation;
import ro.ubbcluj.map.socialnetwork.domain.Message;
import ro.ubbcluj.map.socialnetwork.domain.Tuple;
import ro.ubbcluj.map.socialnetwork.domain.validators.ValidationException;
import ro.ubbcluj.map.socialnetwork.observer.Observable;
import ro.ubbcluj.map.socialnetwork.observer.Observer;
import ro.ubbcluj.map.socialnetwork.repository.ConversationDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.PrietenieDBRepository;
import ro.ubbcluj.map.socialnetwork.repository.UserDBRepository;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ConversationService implements Observable {

    private final ConversationDBRepository repo;
    private final PrietenieDBRepository prietenieDBRepository;
    private final UserDBRepository userDBRepository;

    private final List<Observer> observers = new ArrayList<>();

    public ConversationService(ConversationDBRepository repo, PrietenieDBRepository prietenieDBRepository, UserDBRepository userDBRepository) {
        this.repo = repo;
        this.prietenieDBRepository = prietenieDBRepository;
        this.userDBRepository = userDBRepository;
    }

    public void addMessage(Conversation conversation) throws SQLException {
        if(prietenieDBRepository.findOne(new Tuple<>(conversation.getReceiver().getId(), conversation.getSender().getId())).isEmpty()
        && prietenieDBRepository.findOne((new Tuple<>(conversation.getSender().getId(), conversation.getReceiver().getId()))).isEmpty()) {
            throw new ValidationException("Nu sunteti prieteni, deci nu ii poti trimite mesaje!");
        }

        List<Conversation> all = (List<Conversation>) getAll();
        long id;
        if (all.isEmpty()) {
            id = 1;
        } else {
            int lastIndex = all.size() - 1;
            id = all.get(lastIndex).getId() + 1;
        }

        conversation.setId(id);
        if(conversation.getIdReply()==0)
            conversation.setIdReply(null);
        repo.save(conversation);
        notifyAllObservers();

    }

    public List<Conversation> chat(Long id1, Long id2) {
        List<Conversation> allConversations = (List<Conversation>) getAll();
        List<Conversation> conversationMessages = new ArrayList<>();

        for (Conversation conversation: allConversations) {
            if (isPartOfConversation(conversation, id1, id2)) {
                conversation.setSender(userDBRepository.findOne(id1).orElseThrow());
                conversation.setReceiver(userDBRepository.findOne(id2).orElseThrow());
                if(conversation.getIdReply()!=0) {
                    String msg = conversation.getMessage().getText();
                    Message message = repo.findMessage(conversation.getIdReply()).get();
                    msg = "Reply la:" + message.getText()
                            + '\n' + msg;
                    conversation.getMessage().setText(msg);
                }
                conversationMessages.add(conversation);
            } else if (isPartOfConversation(conversation, id2, id1)) {
                conversation.setSender(userDBRepository.findOne(id2).orElseThrow());
                conversation.setReceiver(userDBRepository.findOne(id1).orElseThrow());
                conversationMessages.add(conversation);
            }
        }

        return conversationMessages;
    }

    private boolean isPartOfConversation(Conversation conversation, Long id1, Long id2) {
        return (conversation.getSender().getId().equals(id1) && conversation.getReceiver().getId().equals(id2));
    }

    public Long generateIdMessage(){

        long id;
        List<Message> all = (List<Message>) repo.findAllMessages();
        if (all.isEmpty()) {
            id = 1L;
        } else {
            int lastIndex = all.size() - 1;
            id = all.get(lastIndex).getId() + 1;
        }
        return id;
    }


    private Iterable<Conversation> getAll()
    {
        return repo.findAll();
    }

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyAllObservers() throws SQLException {
        for (Observer observer : observers) {
            observer.update();
        }
    }
}
