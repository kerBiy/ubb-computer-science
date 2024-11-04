package test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;

import org.junit.Before;
import org.junit.Test;

import domain.Vehicle;
import repository.VehicleRepository;
import repository.VehicleRepositoryImpl;
import service.VehicleService;
import service.VehicleServiceImpl;
import utils.MileageUnit;

public class VehicleServiceTest {
	
	private static final String LICENSE_PLATE="CJ09RMN";
	
	private VehicleService vehicleService;
	private VehicleRepository vehicleRepository;
	
	@Before
	public void setUp(){
		vehicleRepository = new VehicleRepositoryImpl();
		vehicleService = new VehicleServiceImpl(vehicleRepository);
		
		//given
		prepareDataForTest();
	}
	
	@Test
	public void testSearchVehiclesWhenValidLicensePlate(){
		//when
		Vehicle foundVehicle  = vehicleService.searchVehicle(LICENSE_PLATE);
		
		//then
		assertNotNull(foundVehicle);
		assertEquals(LICENSE_PLATE,foundVehicle.getLicensePlate());
	}
	
	@Test
	public void searchVehiclesWhenWrongLicensePlate(){
		//when
		Vehicle noVehicle = vehicleService.searchVehicle("ZMS12");
		
		//then
		assertNull(noVehicle);
	}
	
	private void prepareDataForTest(){
		Vehicle vehicle = new Vehicle(LICENSE_PLATE,255.5,2012,MileageUnit.MILE);
		Vehicle vehicle2 = new Vehicle("SJ10DNR",300.0,2019,MileageUnit.KM);
		
		vehicleRepository.addVehicle(vehicle);
		vehicleRepository.addVehicle(vehicle2);
	}
}
