package ro.map.practic1.domain;

public class Table extends Entity<Integer> {
    public Table(Integer id) {
        super(id);
    }

    @Override
    public String toString() {
        return "Table " + getId();
    }
}
