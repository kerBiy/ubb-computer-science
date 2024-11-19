package domain;

public class ServiceProvider {
    private String pic;
    private String phoneNumber;
    private GPSCoordinates coordinates;

    public ServiceProvider(String pic, String phoneNumber, GPSCoordinates coordinates) {
        this.pic = pic;
        this.phoneNumber = phoneNumber;
        this.coordinates = coordinates;
    }

    public String getPic() {
        return pic;
    }

    public void setPic(String pic) {
        this.pic = pic;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public GPSCoordinates getCoordinates() {
        return coordinates;
    }

    public void setCoordinates(GPSCoordinates coordinates) {
        this.coordinates = coordinates;
    }

    @Override
    public String toString() {
        return "ServiceProvider{" +
                "pic='" + pic + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", coordinates=" + coordinates +
                '}';
    }
}
