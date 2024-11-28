package ro.ubbcluj.map.socialnetwork.domain;

import java.time.LocalDateTime;

public class Message extends Entity<Long> {

    private String text;
    private Long idReply;



    public Message(String text) {
        this.text = text;
    }

    public String getText() {
        return text;
    }

    public void setText(String text) {
        this.text = text;
    }



}