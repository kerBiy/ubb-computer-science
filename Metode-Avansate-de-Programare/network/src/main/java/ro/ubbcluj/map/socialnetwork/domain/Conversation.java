package ro.ubbcluj.map.socialnetwork.domain;

import java.time.LocalDateTime;

public class Conversation extends Entity<Long> {
    private Utilizator sender;
    private Utilizator receiver;
    private Message message;
    private LocalDateTime date;
    private Long idReply;

    public Conversation(Utilizator sender, Utilizator receiver, Message message) {
        this.sender = sender;
        this.receiver = receiver;
        this.message = message;
        this.date = LocalDateTime.now();
    }

    public long getIdReply() {
        if(idReply!=null)
            return idReply;
        else
            return 0;
    }

    public void setIdReply(Long idReply) {
        this.idReply = idReply;
    }

    public Utilizator getSender() {
        return sender;
    }

    public void setSender(Utilizator sender) {
        this.sender = sender;
    }

    public Utilizator getReceiver() {
        return receiver;
    }

    public void setReceiver(Utilizator receiver) {
        this.receiver = receiver;
    }

    public Message getMessage() {
        return message;
    }

    public void setMessage(Message message) {
        this.message = message;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date =date;
    }
}
