package ubb.map.practic2023v1.domain;

import java.time.LocalDate;

public class Reservation extends Entity<Double> {
    private Double clientId;
    private Double hotelId;
    private LocalDate startDate;
    private Integer noNights;

    public Reservation(Double id, Double clientId, Double hotelId, LocalDate startDate, Integer noNights) {
        super(id);
        this.clientId = clientId;
        this.hotelId = hotelId;
        this.startDate = startDate;
        this.noNights = noNights;
    }

    public Double getClientId() {
        return clientId;
    }

    public void setClientId(Double clientId) {
        this.clientId = clientId;
    }

    public Double getHotelId() {
        return hotelId;
    }

    public void setHotelId(Double hotelId) {
        this.hotelId = hotelId;
    }

    public LocalDate getStartDate() {
        return startDate;
    }

    public void setStartDate(LocalDate startDate) {
        this.startDate = startDate;
    }

    public Integer getNoNights() {
        return noNights;
    }

    public void setNoNights(Integer noNights) {
        this.noNights = noNights;
    }
}
