package test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

import domain.Vehicle;
import repository.VehicleRepository;
import repository.VehicleRepositoryImpl;
import utils.MileageUnit;

public class VehicleRepositoryTest {
	
	private VehicleRepository vehicleRepository;
	
	@Before
	public void setUp(){
		this.vehicleRepository = new VehicleRepositoryImpl();
	}
	
	@Test
	public void testAddVehicleWithSucces(){
		
		//given
		int noOfVehicles = vehicleRepository.getNumberOfVehicles();
		Vehicle toBeAdded = new Vehicle("MM20MDM", 0.0, 2019, MileageUnit.KM);
		
		//when
		vehicleRepository.addVehicle(toBeAdded);
	     
		assertEquals(noOfVehicles+1,vehicleRepository.getNumberOfVehicles());	
	}

	@Test
	public void testAddVehiclesWhenInvalidConditions(){
		//given
		int noOfVehicles = vehicleRepository.getNumberOfVehicles();
		
		Vehicle vehicle = new Vehicle("DJ10CMM",100.11,2019,MileageUnit.KM);
		vehicle.setInactive();
		
		vehicleRepository.addVehicle(vehicle);
		
		//no changes in the stock, vehicle was not added
		assertTrue(noOfVehicles==vehicleRepository.getNumberOfVehicles());
	}
	
	@Test
	public void testDeleteVehicleWithSucces(){
		//given 
		Vehicle vehicle = new Vehicle("TM11MMM",100.1,1965,MileageUnit.KM);
		vehicleRepository.addVehicle(vehicle);
		
		//when
		vehicleRepository.deleteVehicle(vehicle);
		
		//then
		assertTrue(vehicle.isInactive());
	}
}

