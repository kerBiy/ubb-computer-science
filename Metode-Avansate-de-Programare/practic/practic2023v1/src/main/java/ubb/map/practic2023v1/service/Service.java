package ubb.map.practic2023v1.service;

import ubb.map.practic2023v1.domain.Hotel;
import ubb.map.practic2023v1.domain.Location;
import ubb.map.practic2023v1.domain.SpecialOffer;
import ubb.map.practic2023v1.repository.*;

import java.time.LocalDate;
import java.util.*;
import java.util.stream.Collectors;

public class Service {
    private LocationRepository locationRepository;
    private HotelRepository hotelRepository;
    private SpecialOfferRepository specialOfferRepository;
    private ClientRepository clientRepository;
    private ReservationRepository reservationRepository;

    public Service(LocationRepository locationRepository, HotelRepository hotelRepository, SpecialOfferRepository specialOfferRepository, ClientRepository clientRepository, ReservationRepository reservationRepository) {
        this.locationRepository = locationRepository;
        this.hotelRepository = hotelRepository;
        this.specialOfferRepository = specialOfferRepository;
        this.clientRepository = clientRepository;
        this.reservationRepository = reservationRepository;
    }

    public List<Location> getAllLocations() {
        // Return all locations
        return (List<Location>) locationRepository.findAll();
    }

    public List<Hotel> getHotelsByLocation(String locationName) {
        // Filter hotels by location name
        return ((List<Hotel>) hotelRepository.findAll()).stream()
                .filter(hotel -> {
                    Location location = locationRepository.findOne(hotel.getLocationId()).orElse(null);
                    return location != null && locationName.equals(location.getLocationName());
                })
                .collect(Collectors.toList());
    }

    public List<SpecialOffer> getOffersByHotelAndPeriod(Hotel hotel, LocalDate startDate, LocalDate endDate) {
        // Convert LocalDate to java.util.Date
        Date start = java.sql.Date.valueOf(startDate);
        Date end = java.sql.Date.valueOf(endDate);

        // Filter offers for a specific hotel and period
        return ((List<SpecialOffer>) specialOfferRepository.findAll()).stream()
                .filter(offer -> offer.getHotelId().equals(hotel.getId())
                        && (offer.getStartDate().equals(start) || offer.getStartDate().after(start))
                        && (offer.getEndDate().equals(end) || offer.getEndDate().before(end)))
                .collect(Collectors.toList());
    }
}
