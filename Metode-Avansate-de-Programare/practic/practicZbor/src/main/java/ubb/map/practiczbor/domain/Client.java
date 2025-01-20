package ubb.map.practiczbor.domain;

public class Client implements Entity<String> {
    private String username;
    private String name;

    public Client(String username, String name) {
        this.username = username;
        this.name = name;
    }

    @Override
    public String getId() {
        return username;
    }

    @Override
    public void setId(String username) {
        this.username = username;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
