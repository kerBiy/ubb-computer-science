package ro.map.practic1.service;

import ro.map.practic1.domain.MenuItem;
import ro.map.practic1.domain.Order;
import ro.map.practic1.domain.Table;
import ro.map.practic1.repository.MenuItemRepository;
import ro.map.practic1.repository.OrderRepository;
import ro.map.practic1.repository.TableRepository;
import ro.map.practic1.utils.Observable;

import java.util.*;
import java.util.stream.Collectors;

public class Service extends Observable {
    private final TableRepository tableRepository;
    private final MenuItemRepository menuItemRepository;
    private final OrderRepository orderRepository;

    public Service(TableRepository tableRepository, MenuItemRepository menuItemRepository, OrderRepository orderRepository) {
        this.tableRepository = tableRepository;
        this.menuItemRepository = menuItemRepository;
        this.orderRepository = orderRepository;
    }

    public Iterable<Table> getTables() {
        return tableRepository.findAll();
    }

    public Map<String, List<MenuItem>> getMenuGroupedByCategory() {
        ArrayList<MenuItem> menuItems = (ArrayList<MenuItem>) menuItemRepository.findAll();
        return menuItems.stream().collect(Collectors.groupingBy(MenuItem::getCategory));
    }

    public int generateOrderId() {
        List<Order> orders = (List<Order>) orderRepository.findAll();
        return orders.isEmpty() ? 1 : orders.stream().mapToInt(Order::getId).max().getAsInt() + 1;
    }

    public void saveOrder(Order order) {
        orderRepository.save(order);
        notifyObservers();
    }

    public List<Order> getOrdersSortedByDate() {
        List<Order> orders = (List<Order>) orderRepository.findAll();
        orders.sort(Comparator.comparing(Order::getDate));
        return orders;
    }

    public MenuItem getMenuItemById(Integer id) {
        return menuItemRepository.findOne(id).get();
    }
}
