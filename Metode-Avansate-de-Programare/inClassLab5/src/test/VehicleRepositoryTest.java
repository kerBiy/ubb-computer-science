package test;
import static org.junit.Assert.assertTrue;

import java.util.List;

import org.junit.Before;
import org.junit.Test;

import domain.Vehicle;
import repository.VehicleRepository;
import repository.VehicleRepositoryImpl;

public class VehicleRepositoryTest {
	
	private static final String PROPERTY_TO_LOAD_DATA="vehicleTestLoadFile";
	private VehicleRepository vehicleRepository;
	
	@Before
	public void setUp(){
		this.vehicleRepository = new VehicleRepositoryImpl();
		vehicleRepository.initialLoadOfVehicles(PROPERTY_TO_LOAD_DATA);
	}
	
	
	@Test
	public void testDeleteVehicleWithSucces(){
		//given 
		List<Vehicle>vehicles = vehicleRepository.getVehicles();
		
		Vehicle vehicle = vehicles.get(0);
		
		//when
		vehicleRepository.deleteVehicle(vehicle);
		
		//then
		assertTrue(vehicle.isInactive());
	}
}

