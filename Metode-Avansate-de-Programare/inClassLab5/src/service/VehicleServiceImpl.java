package service;

import java.util.List;

import domain.Vehicle;
import exceptions.NoDataAvailableException;
import repository.VehicleRepository;

public class VehicleServiceImpl implements VehicleService {
	private static final String PROPERTY_TO_LOAD_DATA="vehicleInitialLoadFile";
	
	private VehicleRepository vehicleRepository;

	public VehicleServiceImpl(VehicleRepository vehicleRepository) {
		this.vehicleRepository = vehicleRepository;
	}

	@Override
	public Vehicle searchVehicle(String licensePlate) {
		// we will proceed with an exact search for the license plate

		List<Vehicle> vehicles = vehicleRepository.getVehicles();
		for (int i = 0; i < vehicles.size(); i++) {
			Vehicle currentVehicle = vehicles.get(i);

			if (licensePlate.equals(currentVehicle.getLicensePlate())) {
				return currentVehicle;
			}
		}

		return null;
	}

	@Override
	public List<Vehicle> getAll() throws NoDataAvailableException{
	
		vehicleRepository.initialLoadOfVehicles(PROPERTY_TO_LOAD_DATA);
		
		List<Vehicle>vehicles = vehicleRepository.getVehicles();
		
		if(vehicles.size()==0){
			throw new NoDataAvailableException("There is no vehicle in the system !");
		}
		
		return vehicles;
	}
}
