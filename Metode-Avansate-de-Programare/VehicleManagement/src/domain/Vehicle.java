package domain;

import utils.MileageUnit;

public class Vehicle {

	private String licensePlate;
	private Double mileage;
	private Integer year;
	private MileageUnit mileageUnit;
	private boolean inactive;

	public Vehicle() {
		System.out.println("Default constructor");
	}

	public Vehicle(String licensePlate, Double newMileage, Integer year, MileageUnit mileageUnit) {
		this.licensePlate = licensePlate;
		mileage = newMileage;
		this.year = year;
		this.mileageUnit = mileageUnit;
		this.inactive = Boolean.FALSE;// at the beginning all vehicles are
										// active
	}

	public String getLicensePlate() {
		return this.licensePlate;
	}

	public void setMileage(Double mileage) {
		this.mileage = mileage;
	}

	public Integer getYear() {
		return this.year;
	}

	public boolean isInactive() {
		return this.inactive;
	}

	public void setInactive() {
		this.inactive = Boolean.TRUE;
	}

	public void printVehicleDetails() {
		System.out.println("Vehicle has license plate:" + licensePlate + ", current mileage:" + mileage + " and unit:"
				+ mileageUnit + " and it was produced in " + year);
	}
}
