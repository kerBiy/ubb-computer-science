package org.university.socialapp.Domain;

import java.time.LocalDateTime;

public class Message implements Entity<Long> {
    private Long id;
    private String text;
    private Long sender;
    private Conversation perentConversation;
    private LocalDateTime dateTime;

    public Message(Long id, String text, Long sender, Conversation perentConversation) {
        this.id = id;
        this.text = text;
        this.sender = sender;
        this.perentConversation = perentConversation;
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

    public Long getSender() {
        return sender;
    }

    public Conversation getPerentConversation() {
        return perentConversation;
    }

    public LocalDateTime getDateTime() {
        return dateTime;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setSender(Long sender) {
        this.sender = sender;
    }

    public void setPerentConversation(Conversation perentConversation) {
        this.perentConversation = perentConversation;
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
                ", perentConversation=" + perentConversation +
                '}';
    }
}
