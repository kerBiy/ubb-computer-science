package service;

import domain.GPSCoordinates;
import domain.ServiceProvider;

public interface ServiceProviderService {

    ServiceProvider getNearestServiceProvider(GPSCoordinates customerBreakdown);
}
