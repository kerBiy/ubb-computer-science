namespace PeopleApp
{
    public class Student : Person
    {
        public void ShowAge()
        {
            Console.WriteLine($"My age is: {age} years old");
        }
    }
}