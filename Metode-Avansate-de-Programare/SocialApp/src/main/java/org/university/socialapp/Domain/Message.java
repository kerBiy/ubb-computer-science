package org.university.socialapp.Domain;

import java.time.LocalDateTime;

public class Message implements Entity<Long> {
    private Long id;
    private String text;
    private String sender;
    private Conversation parentConversation;
    private LocalDateTime dateTime;

    public Message(Long id, String text, String sender, Conversation perentConversation, LocalDateTime localDateTime) {
        this.id = id;
        this.text = text;
        this.sender = sender;
        this.parentConversation = perentConversation;
        this.dateTime = LocalDateTime.now();
    }

    @Override
    public Long getId() {
        return id;
    }

    @Override
    public void setId(Long id) {
        this.id = id;
    }

    public String getText() {
        return text;
    }

    public String getSender() {
        return sender;
    }

    public Conversation getParentConversation() {
        return parentConversation;
    }

    public LocalDateTime getDateTime() {
        return dateTime;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setSender(String sender) {
        this.sender = sender;
    }

    public void setParentConversation(Conversation parentConversation) {
        this.parentConversation = parentConversation;
    }

    public void setDateTime(LocalDateTime dateTime) {
        this.dateTime = dateTime;
    }

    @Override
    public String toString() {
        return "Message{" +
                "id=" + id +
                ", text='" + text + '\'' +
                ", sender=" + sender +
                ", parentConversation=" + parentConversation +
                '}';
    }
}
