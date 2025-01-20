package ro.map.practic1;

import ro.map.practic1.repository.MenuItemRepository;
import ro.map.practic1.repository.OrderRepository;
import ro.map.practic1.repository.TableRepository;
import ro.map.practic1.service.Service;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) throws SQLException {
        final String url = "jdbc:postgresql://localhost:5432/PracticMAP";
        final String user = "postgres";
        final String password = "nush";

        final Connection dataBaseConnection = DriverManager.getConnection(url, user, password);

        TableRepository tableRepository = new TableRepository(dataBaseConnection);
        MenuItemRepository menuItemRepository = new MenuItemRepository(dataBaseConnection);
        OrderRepository orderRepository = new OrderRepository(dataBaseConnection);

        Service service = new Service(tableRepository, menuItemRepository, orderRepository);

        GUI.setService(service);
        GUI.launch();
    }
}
