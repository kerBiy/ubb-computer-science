package ubb.map.practiczbor;

import ubb.map.practiczbor.repository.ClientRepository;
import ubb.map.practiczbor.repository.FlightRepository;
import ubb.map.practiczbor.repository.TicketRepository;
import ubb.map.practiczbor.service.Service;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException {
        final String url = "jdbc:postgresql://localhost:5432/PracticZbor";
        final String user = "postgres";
        final String password = "nush";

        final Connection dataBaseConnection = DriverManager.getConnection(url, user, password);

        ClientRepository clientRepository = new ClientRepository(dataBaseConnection);
        FlightRepository flightRepository = new FlightRepository(dataBaseConnection);
        TicketRepository ticketRepository = new TicketRepository(dataBaseConnection);

        Service service = new Service(clientRepository, flightRepository, ticketRepository);

        GUI.setService(service);
        GUI.launch();
    }
}
