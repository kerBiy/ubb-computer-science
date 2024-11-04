package sem1_2.model;

import java.util.ArrayList;

public class SortingTask extends Task {
    private ArrayList<Integer> toSort;
    private AbstractSorter sorter;

    public SortingTask(String id, String description, ArrayList<Integer> toSort, AbstractSorter sorter) {
        super(id, description);
        this.toSort = toSort;
        this.sorter = sorter;
    }

    public ArrayList<Integer> getToSort() {
        return toSort;
    }

    public void setToSort(ArrayList<Integer> toSort) {
        this.toSort = toSort;
    }

    public void execute(){
        System.out.println(sorter.sort(toSort));
    }
}
