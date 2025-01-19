package ro.map.practic1.domain;

public class MenuItem extends Entity<Integer> {
    private String category;
    private String item;
    private Float price;
    private String currency;

    public MenuItem(Integer id, String category, String item, Float price, String currency) {
        super(id);
        this.category = category;
        this.item = item;
        this.price = price;
        this.currency = currency;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getItem() {
        return item;
    }

    public void setItem(String item) {
        this.item = item;
    }

    public Float getPrice() {
        return price;
    }

    public void setPrice(Float price) {
        this.price = price;
    }

    public String getCurrency() {
        return currency;
    }

    public void setCurrency(String currency) {
        this.currency = currency;
    }

    @Override
    public String toString() {
        return getId() + "," + category + "," + item + "," + price + "," + currency;
    }
}
