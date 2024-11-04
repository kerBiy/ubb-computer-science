package service;

import domain.Vehicle;

/**
 * Service that handles the business logic regarding vehicle entity
 * 
 * @author SERGIU
 *
 */
public interface VehicleService {
	/**
	 * Search a vehicle after license plate
	 * 
	 * @param licensePlate
	 *            unique identifier for a vehicle
	 * @return the found entity
	 */
	Vehicle searchVehicle(String licensePlate);

}
