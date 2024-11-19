package repository;

import java.util.List;

import domain.Customer;

/**
 * Repository that handles customers
 * 
 * @author SERGIU
 *
 */
public interface CustomerRepository {
	
	/**
	 * Add a new customer into the system, data is saved into a text file
	 * @param customer a new potential client that can achieve a vehicle
	 * @return the created customer without an assigned vehicle
	 */
	void addCustomer(Customer customer);
	
	/**
	 * Initialized a list with customers from the system
	 */
	void initialLoadOfCustomers(String property);
	
	List<Customer>getAllCustomers(String property);
}
