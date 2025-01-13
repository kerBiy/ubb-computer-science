using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class QueueContainer : AbstractContainer
{
    public override Task remove()
    {
        if (!base.isEmpty())
        {
            Task t = tasks.ElementAt(0);
            tasks.RemoveAt(0);
            return t;
        }
        else
        {
            return null;
        }
    }
}