package org.university.socialapp.Domain;

public class Friendship implements Entity<String> {
    private Long user1;
    private Long user2;

    public Friendship(Long user1, Long user2) {
        this.user1 = user1;
        this.user2 = user2;
    }

    public Friendship(User user1, User user2) {
        this.user1 = user1.getId();
        this.user2 = user2.getId();
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

    @Override
    public String toString() {
        return user1 + "," + user2;
    }
}