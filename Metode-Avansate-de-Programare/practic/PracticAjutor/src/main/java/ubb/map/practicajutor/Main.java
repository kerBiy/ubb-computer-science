package ubb.map.practicajutor;

import ubb.map.practicajutor.repository.*;
import ubb.map.practicajutor.service.Service;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException {
        final String url = "jdbc:postgresql://localhost:5432/PracticAjutor";
        final String user = "postgres";
        final String password = "nush";

        final Connection dataBaseConnection = DriverManager.getConnection(url, user, password);

        PersoanaRepository persoanaRepository = new PersoanaRepository(dataBaseConnection);
        NevoieRepository nevoieRepository = new NevoieRepository(dataBaseConnection);

        Service service = new Service(persoanaRepository, nevoieRepository);

        GUI.setService(service);
        GUI.launch();
    }
}

