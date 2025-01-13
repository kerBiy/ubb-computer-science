using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;
public class StackContainer :AbstractContainer
{
    public override Task remove()
    {
        if (!base.isEmpty())
        {
            Task t = tasks.ElementAt(tasks.Count() - 1);
            tasks.RemoveAt(tasks.Count() - 1);
            return t;
        }
        else
        {
            return null;
        }
    }

}
