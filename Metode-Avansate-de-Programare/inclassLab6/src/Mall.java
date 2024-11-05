public class Mall {
    private String name;
    private String manager;
    private Integer year;
    private Double profit;

    public Mall(String name, String manager, Integer year, Double profit) {
        this.name = name;
        this.manager = manager;
        this.year = year;
        this.profit = profit;
    }

    public String getName() {
        return name;
    }

    public String getManager() {
        return manager;
    }

    public Integer getYear() {
        return year;
    }

    public Double getProfit() {
        return profit;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setManager(String manager) {
        this.manager = manager;
    }

    public void setYear(Integer year) {
        this.year = year;
    }

    public void setProfit(Double profit) {
        this.profit = profit;
    }

    @Override
    public String toString() {
        return "Mall{" +
                "name='" + name + '\'' +
                ", manager='" + manager + '\'' +
                ", year=" + year +
                ", profit=" + profit +
                '}';
    }
}
