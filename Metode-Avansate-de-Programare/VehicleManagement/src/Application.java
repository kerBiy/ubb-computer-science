import repository.CustomerRepository;
import repository.CustomerRepositoryImpl;
import repository.VehicleRepository;
import repository.VehicleRepositoryImpl;
import service.CustomerService;
import service.CustomerServiceImpl;
import service.VehicleService;
import service.VehicleServiceImpl;
import ui.ConsoleUI;

public class Application {

	public static void main(String[] args) {
		VehicleRepository vehicleRepository = new VehicleRepositoryImpl();
		VehicleService vehicleService = new VehicleServiceImpl(vehicleRepository);
		CustomerRepository customerRepository = new CustomerRepositoryImpl();
		CustomerService customerService=new CustomerServiceImpl(customerRepository);
		ConsoleUI consoleUI = new ConsoleUI(vehicleService,customerService);
		consoleUI.displayVehicles();
		
		System.out.println("---------------------------");
		consoleUI.displayCustomers();
		
		System.out.println("----------------------------");
		consoleUI.addCustomer();
		
		System.out.println("-----------------------------");
		consoleUI.displayCustomers();	
	}

}
