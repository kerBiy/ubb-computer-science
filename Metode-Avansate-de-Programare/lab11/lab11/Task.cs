using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public abstract class Task
{
    protected string taskID;
    protected string description;

    protected Task(string taskID, string description)
    {
        this.taskID = taskID;
        this.description = description;
    }

    public string Description
    {
        get { return description; }
        set { description = value; }
    }

    public string TaskID
    {
        get { return taskID; }
        set { taskID = value; }
    }

    protected bool Equals(Task other)
    {
        return taskID == other.taskID && description == other.description;
    }

    public override bool Equals(object? obj)
    {
        if (obj is null) return false;
        if (ReferenceEquals(this, obj)) return true;
        if (obj.GetType() != GetType()) return false;
        return Equals((Task)obj);
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(taskID, description);
    }

    public override string ToString()
    {
        return $" + taskID {taskID}, Description: {description}";
    }

    public abstract void execute();
}