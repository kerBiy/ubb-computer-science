package service;

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import domain.Customer;
import domain.ServiceProvider;
import domain.Vehicle;
import repository.CustomerRepository;

public class CustomerServiceImpl implements CustomerService {

    private CustomerRepository customerRepository;
    private VehicleService vehicleService;
    private ServiceProviderService serviceProviderService;


    public CustomerServiceImpl(CustomerRepository customerRepository, VehicleService vehicleService, ServiceProviderService serviceProviderService) {
        this.customerRepository = customerRepository;
        this.vehicleService = vehicleService;
        this.serviceProviderService = serviceProviderService;
    }


    @Override
    public List<Customer> sortCustomersByNameAscending(String property) {
        List<Customer> customers = getAll(property);

        customers = customers.stream().sorted(Comparator.comparing(Customer::getName)).collect(Collectors.toList());
        return customers;
    }

    @Override
    public void buyVehicle(Customer customer, String licensePlate) {

        Vehicle vehicle = vehicleService.searchVehicle(licensePlate);

        if (vehicle != null) {
            customer.setVehicle(vehicle);
        }
    }


    @Override
    public List<Customer> getAll(String property) {
        return customerRepository.getAllCustomers(property);
    }

    @Override
    public void breakdownScenario(Customer customer) {
        ServiceProvider nearest = serviceProviderService.getNearestServiceProvider(customer.getBreakdown());

        customer.setIsBreakdown(true);

        //call nearest service provider
        //for the moment is a print (bad practice), we can have a messaging system that calls the service provider
        System.out.println("Call the nearest service provider:" + nearest.getPhoneNumber());
    }
}
