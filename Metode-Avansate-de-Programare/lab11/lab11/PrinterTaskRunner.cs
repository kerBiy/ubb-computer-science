using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class PrinterTaskRunner : AbstractTaskRunner
{
    private static readonly string TimeFormat = "HH:mm";

    public PrinterTaskRunner(TaskRunner taskRunner) : base(taskRunner)
    {
    }

    public override void executeOneTask()
    {
        base.executeOneTask();
        Console.WriteLine($"Task executed at: {DateTime.Now.ToString(TimeFormat, CultureInfo.InvariantCulture)}");
    }
}