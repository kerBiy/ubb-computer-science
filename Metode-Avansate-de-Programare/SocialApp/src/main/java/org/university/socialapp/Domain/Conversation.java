package org.university.socialapp.Domain;

import java.util.List;

public class Conversation {
    private List<Long> members;
    private List<Message> messages;

    public Conversation(List<Long> members, List<Message> messages) {
        this.members = members;
        this.messages = messages;
    }

    public List<Long> getMembers() {
        return members;
    }

    public void addMember(Long userId) {
        members.add(userId);
    }

    public void removeMember(Long userId) {
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
