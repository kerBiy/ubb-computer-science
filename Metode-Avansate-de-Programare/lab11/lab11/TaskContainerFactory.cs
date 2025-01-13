using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class TaskContainerFactory : Factory
{
    private static TaskContainerFactory container = null;

    private TaskContainerFactory()
    {
    }

    public static TaskContainerFactory getInstance()
    {
        if (container == null)
        {
            container = new TaskContainerFactory();
        }

        return container;
    }

    public override Container createContainer(Strategy strategy)
    {
        if (strategy == Strategy.FIFO)
        {
            return new QueueContainer();
        }
        else if (strategy == Strategy.LIFO)
        {
            return new StackContainer();
        }

        return null;
    }
}