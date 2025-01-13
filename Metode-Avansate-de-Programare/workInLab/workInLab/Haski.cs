public class Haski : Dog
{
    public int Speed { get; set; }

    public Haski(string name, int age, int speed) : base(name, age)
    {
        Speed = speed;
    }

    public void Run()
    {
        Console.WriteLine($"{Name} is running at {Speed} km/h!");
    }

    public override void Eat()
    {
        Console.WriteLine($"Haski {Name} is eating quickly!");
    }
}