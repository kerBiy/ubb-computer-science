package ubb.map.practiczbor.domain;

import javafx.util.Pair;
import java.time.LocalDateTime;

public class Ticket implements Entity<Pair<String, Long>> {
    private String username;
    private Long flightId;
    private LocalDateTime purchaseTime;

    public Ticket(String username, Long flightId, LocalDateTime purchaseTime) {
        this.username = username;
        this.flightId = flightId;
        this.purchaseTime = purchaseTime;
    }

    @Override
    public Pair<String, Long> getId() {
        return new Pair<>(username, flightId);
    }

    @Override
    public void setId(Pair<String, Long> usernameFlightPair) {
        username = usernameFlightPair.getKey();
        flightId = usernameFlightPair.getValue();
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public Long getFlightId() {
        return flightId;
    }

    public void setFlightId(Long flightId) {
        this.flightId = flightId;
    }

    public LocalDateTime getPurchaseTime() {
        return purchaseTime;
    }

    public void setPurchaseTime(LocalDateTime purchaseTime) {
        this.purchaseTime = purchaseTime;
    }
}
