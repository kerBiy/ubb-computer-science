using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class MessageTask : Task
{
    private string message;
    private string from;
    private string to;
    private DateTime date;

    public MessageTask(string taskID, string description, string message, string from, string to, DateTime date) : base(
        taskID, description)
    {
        this.message = message;
        this.from = from;
        this.date = date;
    }

    public override void execute()
    {
        //Console.WriteLine(taskID + " " + description + " " + from + " " + message + " " + date);
    }

    public string Message
    {
        get { return message; }
        set { message = value; }
    }

    public string To
    {
        get { return to; }
        set { to = value; }
    }

    public string From
    {
        get { return from; }
        set { from = value; }
    }

    public DateTime Date
    {
        get { return date; }
        set { date = value; }
    }
}