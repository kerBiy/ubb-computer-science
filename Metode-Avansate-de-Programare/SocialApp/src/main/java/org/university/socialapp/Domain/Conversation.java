package org.university.socialapp.Domain;

import java.util.List;

public class Conversation implements Entity<Long> {
    private Long id;
    private List<String> members;
    private List<Message> messages;

    public Conversation(Long id, List<String> members, List<Message> messages) {
        this.id = id;
        this.members = members;
        this.messages = messages;
    }

    @Override
    public Long getId() {
        return id;
    }

    @Override
    public void setId(Long id) {
        this.id = id;
    }

    public List<String> getMembers() {
        return members;
    }

    public void addMember(String userId) {
        members.add(userId);
    }

    public void removeMember(String userId) {
        members.remove(userId);
    }

    public List<Message> getMessages() {
        return messages;
    }

    public void addMessage(Message message) {
        messages.add(message);
    }

    public void removeMessage(Message message) {
        messages.remove(message);
    }
}
