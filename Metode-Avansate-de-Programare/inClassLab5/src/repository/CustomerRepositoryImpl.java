package repository;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import domain.Customer;
import utils.IOHandler;

public class CustomerRepositoryImpl implements CustomerRepository {

	private static final String PATH_TO_CUSTOMER_FILE = "customerInitialLoadFile";

	private List<Customer> customers;

	public CustomerRepositoryImpl() {
		customers = new ArrayList<>();
	}

	@Override
	public void addCustomer(Customer customer) {
		try (FileWriter fileWriter = IOHandler.initializeDataWriter(PATH_TO_CUSTOMER_FILE)) {
			fileWriter.write(customer.getPic() + "," + customer.getName() + "," + customer.getAge());
			fileWriter.write("\n");
		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}

	@Override
	public void initialLoadOfCustomers(String property) {
		try (BufferedReader bufferedReader = IOHandler.initializeBufferReader(property)) {
			String line;
			while ((line = bufferedReader.readLine()) != null) {
				String[] arguments = line.split(",");
				Customer customer = new Customer(arguments[0], arguments[1], Integer.parseInt(arguments[2]));
				customers.add(customer);
			}
		} catch (IOException e) {
			System.out.println("Errors while loading data from text file: " + e.getMessage());
		}
	}

	@Override
	public List<Customer> getAllCustomers(String property) {
		customers.clear();
		initialLoadOfCustomers(property);
		return customers;
	}
}