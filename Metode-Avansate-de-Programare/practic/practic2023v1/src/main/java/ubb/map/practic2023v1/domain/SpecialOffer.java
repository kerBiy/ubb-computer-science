package ubb.map.practic2023v1.domain;

import java.util.Date;

public class SpecialOffer extends Entity<Double> {
    private Double hotelId;
    private Date startDate;
    private Date endDate;
    private Integer percents;

    public SpecialOffer(Double id, Double hotelId, Date startDate, Date endDate, Integer percents) {
        super(id);
        this.hotelId = hotelId;
        this.startDate = startDate;
        this.endDate = endDate;
        this.percents = percents;
    }

    public Double getHotelId() {
        return hotelId;
    }

    public void setHotelId(Double hotelId) {
        this.hotelId = hotelId;
    }

    public Date getStartDate() {
        return startDate;
    }

    public void setStartDate(Date startDate) {
        this.startDate = startDate;
    }

    public Date getEndDate() {
        return endDate;
    }

    public void setEndDate(Date endDate) {
        this.endDate = endDate;
    }

    public Integer getPercents() {
        return percents;
    }

    public void setPercents(Integer percents) {
        this.percents = percents;
    }
}
