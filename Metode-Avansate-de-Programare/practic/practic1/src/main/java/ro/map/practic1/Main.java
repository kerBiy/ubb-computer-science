package ro.map.practic1;

import jdk.jfr.FlightRecorderPermission;
import ro.map.practic1.repository.MenuItemRepository;
import ro.map.practic1.repository.OrderRepository;
import ro.map.practic1.repository.TableRepository;
import ro.map.practic1.service.Service;

public class Main {
    public static void main(String[] args) {
        TableRepository tableRepository = new TableRepository("/Users/alexbalta/Developer/ubb-computer-science/Metode" +
                "-Avansate-de-Programare/practic/practic1/src/main/java/ro/map/practic1/data/tables.txt");
        MenuItemRepository menuItemRepository = new MenuItemRepository("/Users/alexbalta/Developer/ubb-computer" +
                "-science/Metode-Avansate-de-Programare/practic/practic1/src/main/java/ro/map/practic1/data/menu_items.txt");
        OrderRepository orderRepository = new OrderRepository("/Users/alexbalta/Developer/ubb-computer-science/Metode" +
                "-Avansate-de-Programare/practic/practic1/src/main/java/ro/map/practic1/data/orders.txt", "/Users" +
                "/alexbalta/Developer/ubb-computer-science/Metode-Avansate-de-Programare/practic/practic1/src/main/java/ro/map/practic1/data/order_items.txt");
        Service service = new Service(tableRepository, menuItemRepository, orderRepository);

        GUI.setService(service);
        GUI.launch();
    }
}
