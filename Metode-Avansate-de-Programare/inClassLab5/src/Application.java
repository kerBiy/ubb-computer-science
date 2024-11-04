import repository.CustomerRepository;
import repository.CustomerRepositoryImpl;
import repository.VehicleRepository;
import repository.VehicleRepositoryImpl;
import service.VehicleService;
import service.VehicleServiceImpl;
import ui.ConsoleUI;

public class Application {

	public static void main(String[] args) {
		VehicleRepository vehicleRepository = new VehicleRepositoryImpl();
		VehicleService vehicleService = new VehicleServiceImpl(vehicleRepository);
		CustomerRepository customerRepository = new CustomerRepositoryImpl();
		ConsoleUI consoleUI = new ConsoleUI(vehicleService,customerRepository);
		consoleUI.displayVehicles();
		
		System.out.println("---------------------------");
		consoleUI.displayCustomers();
		
		System.out.println("----------------------------");
		consoleUI.addCustomer();
		
		System.out.println("-----------------------------");
		consoleUI.displayCustomers();	
	}

}
