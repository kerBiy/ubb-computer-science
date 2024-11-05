package ui;

import java.util.List;
import java.util.Scanner;

import domain.Customer;
import domain.Vehicle;
import exceptions.NoDataAvailableException;
import repository.CustomerRepository;
import service.CustomerService;
import service.VehicleService;

public class ConsoleUI {

	private static final String PATH_TO_CUSTOMER_FILE = "customerInitialLoadFile";

	private VehicleService vehicleService;
	private CustomerService customerService;

	public ConsoleUI(VehicleService vehicleService, CustomerService customerService) {
		this.vehicleService = vehicleService;
		this.customerService=customerService;
	}

	public void displayVehicles() {
		try {
			List<Vehicle> vehicles = vehicleService.getAll();

			System.out.println("The available vehicles in the system are:");

			vehicles.forEach(Vehicle::printVehicleDetails);
		} catch (NoDataAvailableException e) {
			System.out.println(e.getMessage());
		}
	}

	public void addCustomer() {
		System.out.println("Give details about a customer:");
		String name, pic;
		Integer age;

		Scanner scanner = new Scanner(System.in);
		System.out.println("PIC:");
		pic = scanner.nextLine();
		System.out.println("Name:");
		name = scanner.nextLine();
		System.out.println("Age:");
		age = scanner.nextInt();

		Customer customer = new Customer(pic, name, age);

		customerService.addCustomer(customer);
		scanner.close();
	}

	public void displayCustomers() {
		List<Customer> customers = customerService.getAll(PATH_TO_CUSTOMER_FILE);
		if (customers.isEmpty()) {
			System.out.println("There are no customers in the system!");
		} else {
			System.out.println("The available customers are:");

			customers.forEach(customer -> System.out.println(customer.toString()));
		}
	}

}
