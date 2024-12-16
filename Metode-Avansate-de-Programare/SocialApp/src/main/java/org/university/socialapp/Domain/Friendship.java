package org.university.socialapp.Domain;

import java.time.LocalDateTime;

public class Friendship implements Entity<String> {
    private String user1;
    private String user2;

    private LocalDateTime date;
    private String status;

    public Friendship(String user1, String user2, String status, LocalDateTime date) {
        this.user1 = user1;
        this.user2 = user2;
        this.status = status;
        this.date = date;
    }

    public Friendship(User user1, User user2, String status, LocalDateTime date) {
        this.user1 = user1.getId();
        this.user2 = user2.getId();
        this.status = status;
        this.date = date;
    }

    @Override
    public String getId() {
        return user1 + "-" + user2;  // Composite ID as a String.
    }

    @Override
    public void setId(String id) {
        String[] ids = id.split("-");
        this.user1 = ids[0];
        this.user2 = ids[1];
    }

    public String getUser1() {
        return user1;
    }

    public String getUser2() {
        return user2;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return user1 + "," + user2;
    }
}