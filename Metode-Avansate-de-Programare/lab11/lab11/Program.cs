using lab11;

public class Program
{
    public static void Main(String[] args)
    {
        MessageTask msg1 = new MessageTask("1", "feedback lab 2", "Te-ai descurcat bine", "teacher", "student",
            DateTime.Now);
        MessageTask msg2 = new MessageTask("2", "feedback lab 3", "Te-ai descurcat bine", "teacher", "student",
            DateTime.Now);
        MessageTask msg3 = new MessageTask("3", "feedback lab 4", "Te-ai descurcat bine", "teacher", "student",
            DateTime.Now);
        MessageTask msg4 = new MessageTask("4", "feedback lab 5", "Te-ai descurcat bine", "teacher", "student",
            DateTime.Now);
        MessageTask msg5 = new MessageTask("5", "feedback lab 6", "Te-ai descurcat bine", "teacher", "student",
            DateTime.Now);
        MessageTask[] messageTasks = new MessageTask[] { msg1, msg2, msg3, msg4, msg5 };
        foreach (MessageTask messageTask in messageTasks)
        {
            Console.WriteLine(messageTask.ToString());
        }


        TaskRunner strategyTaskRunner = new StrategyTaskRunner(Strategy.FIFO);
        foreach (MessageTask m in messageTasks)
        {
            strategyTaskRunner.addTask(m);
        }

        strategyTaskRunner.executeAll();


        TaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        foreach (MessageTask m in messageTasks)
        {
            strategyTaskRunner.addTask(m);
        }

        printerTaskRunner.executeAll();

        TaskRunner delayTaskRunner = new DelayTaskRunner(strategyTaskRunner);
        foreach (MessageTask m in messageTasks)
        {
            strategyTaskRunner.addTask(m);
        }

        delayTaskRunner.executeAll();

        int[] array1 = new int[] { 5, 3, 8, 4, 2 };
        int[] array2 = new int[] { 12, 7, -1, 9, 0 };

        SortingTask bubbleSortTask = new SortingTask("1", "BubbleSort Task", array1, new BubbleSorter());
        bubbleSortTask.execute();

        SortingTask quickSortTask = new SortingTask("2", "QuickSort Task", array2, new MergeSorter());
        quickSortTask.execute();
    }
}