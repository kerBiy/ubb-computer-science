package repository;

import domain.Vehicle;

/**
 * Repository that handles vehicles (Stock vehicles)
 * 
 * @author SERGIU
 *
 */
public interface VehicleRepository {

	/**
	 * Add a new vehicle into the stock if it respects the following condition:
	 * -there is enough space into the stock -vehicle is not already inactive
	 * (made more than 30 years ago)
	 * 
	 * @param newVehicle
	 *            to be added
	 */
	void addVehicle(Vehicle newVehicle);

	Vehicle getVehicleAtPosition(int position);

	int getNumberOfVehicles();

	Vehicle[] getVehicles();

	/**
	 * Vehicle will be marked as being inactive, if the fabrication year is more
	 * than 30 years
	 * 
	 * @param vehicle
	 */
	void deleteVehicle(Vehicle vehicle);
}
