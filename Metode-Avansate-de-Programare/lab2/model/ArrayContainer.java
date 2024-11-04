package sem1_2.model;

import java.lang.reflect.Array;
import java.util.ArrayList;

public abstract class ArrayContainer implements Container{
    ArrayList<Task> tasks = new ArrayList<>();
    public ArrayContainer() {}
    @Override
    public int size() {
        return tasks.size();
    }

    @Override
    public boolean isEmpty() {
        return tasks.isEmpty();
    }

    @Override
    public void add(Task task) {
        tasks.add(task);
    }
}
