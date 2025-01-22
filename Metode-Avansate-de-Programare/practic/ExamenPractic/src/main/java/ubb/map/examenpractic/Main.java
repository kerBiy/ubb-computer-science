package ubb.map.examenpractic;

import ubb.map.examenpractic.repository.CityRepository;
import ubb.map.examenpractic.repository.TrainStationRepository;
import ubb.map.examenpractic.service.Service;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException {
        final String url = "jdbc:postgresql://localhost:5432/ExamenPractic";
        final String user = "postgres";
        final String password = "nush";

        final Connection dataBaseConnection = DriverManager.getConnection(url, user, password);

        CityRepository cityRepository = new CityRepository(dataBaseConnection);
        TrainStationRepository trainStationRepository = new TrainStationRepository(dataBaseConnection);

        Service service = new Service(cityRepository, trainStationRepository);

        GUI.setService(service);
        GUI.launch();
    }
}
