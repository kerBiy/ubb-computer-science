class Program
{
    static void Main(string[] args)
    {
        List<Dog> dogs = new List<Dog>
        {
            new Haski("Haski1", 3, 40),
            new Haski("Haski2", 5, 50),
            new Labrador("Labrador1", 4, "golden"),
            new Labrador("Labrador2", 6, "black"),
            new Dog("Dog1", 2)
        };

        Console.WriteLine("Toti cainii mananca:");
        foreach (var dog in dogs)
        {
            dog.Eat();
        }

        Console.WriteLine("\nCainii de tip Haski:");
        foreach (var dog in dogs)
        {
            if (dog is Haski haski)
            {
                Console.WriteLine($"Haski: {haski.Name}, Speed: {haski.Speed} km/h");
            }
        }

        Dictionary<int, string> addressDictionary = new Dictionary<int, string>
        {
            { 1, "Str.Progresului" },
            { 2, "Str.Libertatii" },
            { 3, "Str.Unirii" }
        };

        
        Console.WriteLine("\nDictionar de adrese:");
        foreach (var entry in addressDictionary)
        {
            Console.WriteLine($"{entry.Key} -> {entry.Value}");
        }
    }
}