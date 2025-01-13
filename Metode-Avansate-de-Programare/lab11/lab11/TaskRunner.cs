namespace lab11;

public interface TaskRunner
{
    void executeOneTask();
    void executeAll();
    void addTask(Task t);
    bool hasTask();
}