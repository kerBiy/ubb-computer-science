package ubb.map.practic2023v1.domain;

public class Location extends Entity<Double> {
    private String locationName;

    public Location(Double id, String locationName) {
        super(id);
        this.locationName = locationName;
    }

    public String getLocationName() {
        return locationName;
    }

    public void setLocationName(String locationName) {
        this.locationName = locationName;
    }
}
