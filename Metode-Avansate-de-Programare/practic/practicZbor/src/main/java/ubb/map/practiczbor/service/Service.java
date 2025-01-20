package ubb.map.practiczbor.service;

import ubb.map.practiczbor.domain.Client;
import ubb.map.practiczbor.domain.Flight;
import ubb.map.practiczbor.domain.Ticket;
import ubb.map.practiczbor.repository.ClientRepository;
import ubb.map.practiczbor.repository.FlightRepository;
import ubb.map.practiczbor.repository.TicketRepository;
import ubb.map.practiczbor.utils.Observable;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

public class Service extends Observable {
    private ClientRepository clientRepository;
    private FlightRepository flightRepository;
    private TicketRepository ticketRepository;

    public Service(ClientRepository clientRepository, FlightRepository flightRepository, TicketRepository ticketRepository) {
        this.clientRepository = clientRepository;
        this.flightRepository = flightRepository;
        this.ticketRepository = ticketRepository;
    }

    public Optional<Client> findClientByUsername(String username) {
        return clientRepository.findOne(username);
    }

    public List<String> getAllLocations() {
        List<Flight> flights = (List<Flight>) flightRepository.findAll();

        return flights.stream()
                .flatMap(flight -> List.of(flight.getFrom(), flight.getTo()).stream())
                .distinct()
                .collect(Collectors.toList());
    }

    public List<Flight> getFilteredFlights(String from, String to, LocalDate date) {
        List<Flight> flights = (List<Flight>) flightRepository.findAll();

        return flights.stream()
                .filter(flight -> flight.getFrom().equals(from) &&
                        flight.getTo().equals(to) &&
                        flight.getDepartureTime().toLocalDate().equals(date))
                .collect(Collectors.toList());
    }

    public void saveTicket(Ticket ticket) {
        ticketRepository.save(ticket);
        notifyObservers();
    }

    public int getTicketCountForFlight(Long flightId) {
        List<Ticket> tickets = (List<Ticket>) ticketRepository.findAll();

        return (int) tickets.stream()
                .filter(ticket -> ticket.getFlightId().equals(flightId))
                .count();
    }
}
