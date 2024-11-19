package service;

import java.util.List;

import domain.Customer;

public interface CustomerService {

    /**
     * Sort all customers by name, in ascending order
     *
     * @param property property name that points to the resource file of customers
     * @return sorted list
     */
    List<Customer> sortCustomersByNameAscending(String property);

    /**
     * Add a customer into the vehicle management app, adding customer details means that customer wants to buy a vehicle
     * Adding customer with the chosen vehicle
     *
     * @param customer     the client who wants to buy a vehicle
     * @param licensePlate license plate for the desired vehicle
     */
    void buyVehicle(Customer customer, String licensePlate);

    /**
     * Get all customers from the file specified by property
     *
     * @param property from properties file
     * @return list of customers
     */
    List<Customer> getAll(String property);

    /**
     * Handles a breakdown case, compute nearest service provider and set breakdownCase field to true
     *
     * @param customer
     */
    void breakdownScenario(Customer customer);
}
