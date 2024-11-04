package sem1_2.model;

import java.util.ArrayList;

public class QuickSorter extends AbstractSorter {
    public QuickSorter() {}
    public ArrayList<Integer> sort(ArrayList<Integer> list) {
        ArrayList<Integer> copy = new ArrayList<>(list);
        quickSort(copy, 0, copy.size() - 1);
        return copy;
    }
    private void quickSort(ArrayList<Integer> list, int left, int right) {
        if (left < right) {
            int pivot = partition( list, left, right);
            quickSort(list, left, pivot - 1);
            quickSort(list, pivot + 1, right);
        }
    }
    private int partition(ArrayList<Integer> list, int left, int right) {
        int pivot = list.get(right);
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (list.get(j) <= pivot) {
                i++;
                int temp = list.get(i);
                list.set(i, list.get(j));
                list.set(j, temp);
            }
        }
        int temp = list.get(i+1);
        list.set(i+1, list.get(right));
        list.set(right, temp);
        return i+1;
    }
}
