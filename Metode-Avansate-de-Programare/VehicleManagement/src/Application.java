import domain.Vehicle;
import repository.VehicleRepositoryImpl;
import utils.MileageUnit;

public class Application {

	public static void main(String[] args) {
		Vehicle vehicle = new Vehicle("BN01QRM", 250.000, 2019, MileageUnit.MILE);

		VehicleRepositoryImpl repository = new VehicleRepositoryImpl();
		repository.addVehicle(vehicle);

		for (int i = 0; i < repository.getNumberOfVehicles(); i++) {
			Vehicle v = repository.getVehicleAtPosition(i);
			v.printVehicleDetails();
		}
	}

}
