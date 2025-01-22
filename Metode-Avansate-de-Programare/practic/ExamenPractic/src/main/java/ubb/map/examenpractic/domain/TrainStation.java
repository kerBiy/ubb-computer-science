package ubb.map.examenpractic.domain;

public class TrainStation extends Entity<String> {
    private String departureCityId;
    private String destinationCityId;

    public TrainStation(String id, String departureCityId, String destinationCityId) {
        super(id);
        this.departureCityId = departureCityId;
        this.destinationCityId = destinationCityId;
    }

    public String getDepartureCityId() {
        return departureCityId;
    }

    public void setDepartureCityId(String departureCityId) {
        this.departureCityId = departureCityId;
    }

    public String getDestinationCityId() {
        return destinationCityId;
    }

    public void setDestinationCityId(String destinationCityId) {
        this.destinationCityId = destinationCityId;
    }
}
