public class Labrador : Dog
{
    public string Color { get; set; }

    public Labrador(string name, int age, string color) : base(name, age)
    {
        Color = color;
    }

    public override void Eat()
    {
        Console.WriteLine($"Labrador {Name} with color {Color} is eating.");
    }
}