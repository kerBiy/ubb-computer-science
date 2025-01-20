package ubb.map.practic2023v1;

import ubb.map.practic2023v1.repository.*;
import ubb.map.practic2023v1.service.Service;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException {
        final String url = "jdbc:postgresql://localhost:5432/Practic2023v1";
        final String user = "postgres";
        final String password = "nush";

        final Connection dataBaseConnection = DriverManager.getConnection(url, user, password);

        LocationRepository locationRepository = new LocationRepository(dataBaseConnection);
        HotelRepository hotelRepository = new HotelRepository(dataBaseConnection);
        SpecialOfferRepository specialOfferRepository = new SpecialOfferRepository(dataBaseConnection);
        ClientRepository clientRepository = new ClientRepository(dataBaseConnection);
        ReservationRepository reservationRepository = new ReservationRepository(dataBaseConnection);

        Service service = new Service(locationRepository, hotelRepository, specialOfferRepository, clientRepository,
                reservationRepository);

        GUI.setService(service);
        GUI.launch();
    }
}
