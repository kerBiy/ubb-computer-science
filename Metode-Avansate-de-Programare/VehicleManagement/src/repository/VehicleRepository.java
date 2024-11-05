package repository;

import java.util.List;

import domain.Vehicle;

/**
 * Repository that handles vehicles (Stock vehicles)
 * 
 * @author SERGIU
 *
 */
public interface VehicleRepository {
	/**
	 * Load all vehicle data from a path given in a property file
	 * 
	 * @param property
	 *            the path to the data file
	 */
	public void initialLoadOfVehicles(String property);

	List<Vehicle> getVehicles();

	/**
	 * Vehicle will be marked as being inactive, if the fabrication year is more
	 * than 30 years
	 * 
	 * @param vehicle
	 */
	void deleteVehicle(Vehicle vehicle);
}
