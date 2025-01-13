using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

using System;
using System.Threading;

public class DelayTaskRunner : AbstractTaskRunner
{
    public DelayTaskRunner(TaskRunner taskRunner) : base(taskRunner)
    {
    }

    public override void executeOneTask()
    {
        try
        {
            base.executeOneTask();
            Thread.Sleep(1000);
        }
        catch (ThreadInterruptedException e)
        {
            Console.WriteLine(e);
        }
    }
}