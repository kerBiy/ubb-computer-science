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
		return vehicleRepository.getVehicles().stream()
				.filter(vehicle -> licensePlate.equals(vehicle.getLicensePlate()))
				.findFirst()
				.orElse(null);
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
