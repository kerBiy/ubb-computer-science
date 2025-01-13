using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class SortingTask : Task
{
    private int[] vector;
    private AbstractSorter sorter;

    public SortingTask(string id, string description, int[] vector, AbstractSorter sorter) : base(id, description)
    {
        this.vector = vector;
        this.sorter = sorter;
    }

    public override void execute()
    {
        sorter.sort(ref vector);
        Console.WriteLine("Vector after sorting :");
        foreach (int i in vector) Console.WriteLine(i);
    }
}