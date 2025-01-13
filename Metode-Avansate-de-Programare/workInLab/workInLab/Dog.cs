public class Dog
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Dog(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public void Bark()
    {
        Console.WriteLine($"{Name} is barking!");
    }

    public virtual void Eat()
    {
        Console.WriteLine($"{Name} is eating.");
    }
}