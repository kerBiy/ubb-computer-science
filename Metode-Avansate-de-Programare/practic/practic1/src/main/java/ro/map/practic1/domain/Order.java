package ro.map.practic1.domain;

import java.time.LocalDateTime;
import java.util.List;

public class Order extends Entity<Integer> {
    private Integer table;
    private List<Integer> menuItems;
    private LocalDateTime date;
    private OrderStatus status;

    public Order(Integer id, Integer table, List<Integer> menuItems, LocalDateTime date, OrderStatus status) {
        super(id);
        this.table = table;
        this.menuItems = menuItems;
        this.date = date;
        this.status = status;
    }

    public Integer getTable() {
        return table;
    }

    public void setTable(Integer table) {
        this.table = table;
    }

    public List<Integer> getMenuItems() {
        return menuItems;
    }

    public void setMenuItems(List<Integer> menuItems) {
        this.menuItems = menuItems;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public OrderStatus getStatus() {
        return status;
    }

    public void setStatus(OrderStatus status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return getId() + "," + table + "," + date + "," + status;
    }
}
