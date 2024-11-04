package sem1_2;

//import sem1_2.decorator.DelayTaskRunner;
import sem1_2.decorator.DelayTaskRunner;
import sem1_2.decorator.PrinterTaskRunner;
import sem1_2.decorator.StrategyTaskRunner;
import sem1_2.decorator.TaskRunner;
import sem1_2.factory.SortingStrategy;
import sem1_2.factory.Strategy;
import sem1_2.model.BubbleSorter;
import sem1_2.model.MessageTask;
import sem1_2.model.QuickSorter;
import sem1_2.model.SortingTask;

import java.time.LocalDateTime;
import java.util.ArrayList;

public class Sem1_2Test {
    public static MessageTask[] createMessages() {
        MessageTask msg1 = new MessageTask("1", "feedback lab 2", "Te-ai descurcat bine(1)", "teacher", "student", LocalDateTime.now());
        MessageTask msg2 = new MessageTask("2", "feedback lab 3", "Te-ai descurcat bine(2)", "teacher", "student", LocalDateTime.now());
        MessageTask msg3 = new MessageTask("3", "feedback lab 4", "Te-ai descurcat bine(3)", "teacher", "student", LocalDateTime.now());
        MessageTask msg4 = new MessageTask("4", "feedback lab 5", "Te-ai descurcat bine(4)", "teacher", "student", LocalDateTime.now());
        MessageTask msg5 = new MessageTask("5", "feedback lab 6", "Te-ai descurcat bine(5)", "teacher", "student", LocalDateTime.now());

        return new MessageTask[]{msg1, msg2, msg3, msg4, msg5};
    }

    public static void testTask(String[] args){
        MessageTask[] messages = createMessages();

        TaskRunner str1 = new StrategyTaskRunner(Strategy.valueOf(args[0]));
        for (MessageTask m : messages) {
            str1.addTask(m);
        }
        TaskRunner str2 = new DelayTaskRunner(str1);
        TaskRunner str3 = new PrinterTaskRunner(str2);
        str3.executeAll();
    }


    public static void main(String[] args) {
        MessageTask[] messageTasks = createMessages();
        for (MessageTask messageTask: messageTasks) {
            System.out.println(messageTask);
        }

        TaskRunner strategyTaskRunner = new StrategyTaskRunner(Strategy.valueOf(args[0]));
        for (MessageTask m : messageTasks) {
            strategyTaskRunner.addTask(m);
        }
        // t.executeAll();

        TaskRunner printerTaskRunner = new PrinterTaskRunner(strategyTaskRunner);
        printerTaskRunner.executeAll();

        BubbleSorter s1 = new BubbleSorter();
        ArrayList<Integer> numere1 = new ArrayList<>();
        numere1.add(5);
        numere1.add(9);
        numere1.add(3);
        numere1.add(4);
        numere1.add(2);
        numere1.add(1);

        SortingTask st1 = new SortingTask("asd","Sortez",numere1,s1);
        st1.execute();

        QuickSorter s2 = new QuickSorter();
        ArrayList<Integer> numere2 = new ArrayList<>();
        numere2.add(5);
        numere2.add(9);
        numere2.add(3);
        numere2.add(4);
        numere2.add(2);
        numere2.add(1);

        SortingTask st2 = new SortingTask("asd","Sortez",numere2,s2);
        st2.execute();

        testTask(args);
    }
}
