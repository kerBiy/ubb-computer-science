package sem1_2.model;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class StackContainer extends ArrayContainer {
    public StackContainer() {}
    @Override
    public Task remove() {
        if (!tasks.isEmpty()) {
            return tasks.remove(tasks.size() - 1);
        } else {
            return null;
        }
    }

}
