namespace lab11;

using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

public abstract class AbstractContainer : Container
{
    protected List<Task> tasks = new List<Task>();

    public void add(Task task)
    {
        tasks.Add(task);
    }

    public int size()
    {
        return tasks.Count();
    }

    public bool isEmpty()
    {
        return tasks.Count() == 0;
    }

    public abstract Task remove();
}