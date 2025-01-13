using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class StrategyTaskRunner : TaskRunner
{
    private Container container;

    public StrategyTaskRunner(Strategy strategy)
    {
        container = TaskContainerFactory.getInstance().createContainer(strategy);
    }

    public void executeOneTask()
    {
        Task task = container.remove();
        Console.WriteLine(task.TaskID);
        task.execute();
    }

    public void executeAll()
    {
        while (hasTask())
        {
            executeOneTask();
        }
    }

    public void addTask(Task t)
    {
        container.add(t);
    }

    public bool hasTask()
    {
        return !container.isEmpty();
    }
}