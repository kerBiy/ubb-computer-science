package test;

import domain.Customer;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import repository.CustomerRepository;
import repository.CustomerRepositoryImpl;
import utils.IOHandler;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Optional;

import static org.junit.Assert.assertEquals;

public class CustomerRepositoryTest {
	private CustomerRepository customerRepository;

	@Before
	public void setUp() {
		this.customerRepository = new CustomerRepositoryImpl();
	}

	@After
	public void tearDown() {
		try (PrintWriter writer = new PrintWriter("customerInitialLoadFile")) {
		} catch (IOException e) {
			System.out.println("Error clearing test file: " + e.getMessage());
		}}
	}

	@Test
	public void testAddCustomer() {
		Customer testCustomer = new Customer("pic1", "John Doe", 30);
		customerRepository.addCustomer(testCustomer);

		List<Customer> customers = customerRepository.getAllCustomers("customerInitialLoadFile");
		assertEquals(1, customers.size());

		Customer retrievedCustomer = customers.get(0);
		assertEquals("pic1", retrievedCustomer.getPic());
		assertEquals("John Doe", retrievedCustomer.getName());
	}
}