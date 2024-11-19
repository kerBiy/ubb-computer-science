package test;

import domain.Customer;
import domain.GPSCoordinates;
import domain.ServiceProvider;
import org.junit.Before;
import org.junit.Test;
import repository.CustomerRepository;
import repository.CustomerRepositoryImpl;
import repository.VehicleRepository;
import repository.VehicleRepositoryImpl;
import service.CustomerService;
import service.CustomerServiceImpl;
import service.ServiceProviderService;
import service.VehicleService;
import service.VehicleServiceImpl;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.*;

public class ServiceProviderServiceTest {

    private CustomerService customerService;
    private ServiceProviderService serviceProviderService;
    private VehicleService vehicleService;
    private CustomerRepository customerRepository;
    private VehicleRepository vehicleRepository;

    @Before
    public void setUp() {
        serviceProviderService = mock(ServiceProviderService.class);
       
        vehicleRepository = new VehicleRepositoryImpl();
        vehicleService = new VehicleServiceImpl(vehicleRepository);
        customerRepository = new CustomerRepositoryImpl();
        customerService = new CustomerServiceImpl(customerRepository, vehicleService, serviceProviderService);
    }

    @Test
    public void testNearestSP() {
        GPSCoordinates gpsCoordinates = new GPSCoordinates(2.14, 12.4);
        ServiceProvider nearest = new ServiceProvider("12", "Sam", new GPSCoordinates(4.5, 23.70));

        when(serviceProviderService.getNearestServiceProvider(gpsCoordinates)).thenReturn(nearest);
        Customer customer = new Customer("233", "John", 23, null, gpsCoordinates);

        customerService.breakdownScenario(customer);

        assertEquals(Boolean.TRUE, customer.isBreakdown());
    }
}
