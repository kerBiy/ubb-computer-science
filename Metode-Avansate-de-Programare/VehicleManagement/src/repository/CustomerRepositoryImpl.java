package repository;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

import domain.Customer;
import domain.Vehicle;
import utils.IOHandler;

public class CustomerRepositoryImpl implements CustomerRepository {

	private static final String PATH_TO_CUSTOMER_FILE = "customerInitialLoadFile";

	private List<Customer> customers;

	public CustomerRepositoryImpl() {
		customers = new ArrayList<>();
	}

	@Override
	public void addCustomer(Customer customer) {
		FileWriter fileWriter = IOHandler.initializeDataWriter(PATH_TO_CUSTOMER_FILE);
		try {
			fileWriter.write(customer.getPic() + "," + customer.getName() + "," + customer.getAge());
			fileWriter.write("\n");
		} catch (IOException e) {
			System.out.println(e.getMessage());
		} finally {
			try {
				fileWriter.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		}
	}

	@Override
	public void initialLoadOfCustomers(String property) {
		// read from a text file the customer information
		try (BufferedReader bufferedReader = IOHandler.initializeBufferReader(property)) {
			String line;
			while ((line = bufferedReader.readLine()) != null) {
				String[] arguments = line.split(",");
				Customer customer = new Customer(arguments[0], arguments[1], Integer.parseInt(arguments[2]));
				customers.add(customer);
			}

		} catch (IOException e) {
			System.out.println("Errors while loading data from text file:" + e.getStackTrace());
		}

	}

	@Override
	public List<Customer> getAllCustomers(String property) {
		customers.clear();// clear the list of customer before data loading,
							// avoid messing up the data
		initialLoadOfCustomers(property);
		return customers;
	}

}
