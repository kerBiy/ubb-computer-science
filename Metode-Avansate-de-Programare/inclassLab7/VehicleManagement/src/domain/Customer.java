package domain;

public class Customer {
    private String pic;//personal identification code
    private String name;
    private Integer age;
    private Vehicle vehicle;
    private GPSCoordinates breakdown;
    private Boolean isBreakdown=false;

    //initially, the customer doesn't have a vehicle
    public Customer(String pic, String name, Integer age) {
        super();
        this.pic = pic;
        this.name = name;
        this.age = age;
    }

    public Customer(String pic, String name, Integer age, Vehicle vehicle) {
        super();
        this.pic = pic;
        this.name = name;
        this.age = age;
        this.vehicle = vehicle;
    }

    public Customer(String pic, String name, Integer age, Vehicle vehicle,GPSCoordinates breakdown) {
        super();
        this.pic = pic;
        this.name = name;
        this.age = age;
        this.vehicle = vehicle;
        this.breakdown=breakdown;
    }

    public GPSCoordinates getBreakdown() {
        return breakdown;
    }

    public void setBreakdown(GPSCoordinates breakdown) {
        this.breakdown = breakdown;
    }

    public Boolean isBreakdown()
    {
        return this.isBreakdown;
    }

    public void setIsBreakdown(Boolean breakdown) {
        isBreakdown = breakdown;
    }

    public String getPic() {
        return pic;
    }

    public void setPic(String pic) {
        this.pic = pic;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    @Override
    public String toString() {
        return "Customer [pic=" + pic + ", name=" + name + ", age=" + age + ", vehicle=" + vehicle.getLicensePlate() + "]";
    }
}
