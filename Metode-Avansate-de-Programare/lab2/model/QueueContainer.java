package sem1_2.model;

public class QueueContainer extends ArrayContainer{
    public QueueContainer() {}

    @Override
    public Task remove() {
        if (!tasks.isEmpty()) {
            return tasks.remove(0);
        } else {
            return null;
        }
    }
}
