package org.university.socialapp.Domain;

import java.time.LocalDateTime;

public class FriendRequest implements Entity<String> {
    private Long user1;
    private Long user2;

    private String status;
    private LocalDateTime date;

    public FriendRequest(Long user1, Long user2) {
        this.user1 = user1;
        this.user2 = user2;
        this.date = LocalDateTime.now();
    }

    @Override
    public String getId() {
        return user1 + "-" + user2;  // Composite ID as a String.
    }

    @Override
    public void setId(String id) {
        String[] ids = id.split("-");
        this.user1 = Long.parseLong(ids[0]);
        this.user2 = Long.parseLong(ids[1]);
    }

    public Long getUser1() {
        return user1;
    }

    public Long getUser2() {
        return user2;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }
}
