package service;

import java.util.List;

import domain.Vehicle;
import exceptions.NoDataAvailableException;

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
	
	/**
	 * Get all vehicles from the persistance layer
	 * @return the list of available vehicle
	 */
	List<Vehicle>getAll() throws NoDataAvailableException;

}
