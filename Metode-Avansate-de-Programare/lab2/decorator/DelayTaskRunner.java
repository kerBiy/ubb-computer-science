package sem1_2.decorator;

public class DelayTaskRunner extends AbstractTaskRunner {
    public DelayTaskRunner(TaskRunner taskRunner) {
        super(taskRunner);
    }

    @Override
    public void executeOneTask() {
        try {
            Thread.sleep(3000);
            System.out.println("Am intarziat");
            super.executeOneTask();
        }
        catch (InterruptedException e) {
            super.executeOneTask();
        }
    }
}
