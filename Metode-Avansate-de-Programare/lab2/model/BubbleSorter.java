package sem1_2.model;

import java.util.ArrayList;

public class BubbleSorter extends AbstractSorter {
    public BubbleSorter() {}
    public ArrayList<Integer> sort(ArrayList<Integer> list) {
        int n = list.size();
        for (int i = 0; i < n - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if(list.get(j) > list.get(j+1)) {
                    int temp = list.get(j);
                    list.set(j, list.get(j+1));
                    list.set(j+1, temp);
                    swapped = true;
                }
            }
            if(!swapped) {
                return list;
            }
        }
        return list;
    }
}
