package service;

import java.util.List;
import domain.Customer;

public interface CustomerService {

	/**
	 * Sort all customers by name, in ascending order
	 * 
	 * @return sorted list
	 */
	List<Customer> sortCustomersByNameAscending();

	void addCustomer(Customer customer);

	/**
	 * Get all customers from the file specified by property
	 * 
	 * @param property
	 *            from properties file
	 * @return list of customers
	 */
	List<Customer> getAll(String property);
}
