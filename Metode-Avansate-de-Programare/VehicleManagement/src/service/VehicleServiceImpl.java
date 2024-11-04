package service;

import domain.Vehicle;
import repository.VehicleRepository;

public class VehicleServiceImpl implements VehicleService {

	private VehicleRepository vehicleRepository;

	public VehicleServiceImpl(VehicleRepository vehicleRepository) {
		this.vehicleRepository = vehicleRepository;
	}

	@Override
	public Vehicle searchVehicle(String licensePlate) {
		// we will proceed with an exact search for the license plate

		for (int i = 0; i < vehicleRepository.getNumberOfVehicles(); i++) {
			Vehicle currentVehicle = vehicleRepository.getVehicleAtPosition(i);

			if (licensePlate.equals(currentVehicle.getLicensePlate())) {
				return currentVehicle;
			}
		}
		
		return null;
	}
}
