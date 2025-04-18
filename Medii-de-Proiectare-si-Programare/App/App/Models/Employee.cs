namespace App.Models;

public class Employee : IIdentifiable<long>
{
    public long Id { get; set; }
    public string Username { get; set; }
    public string Password { get; set; }

    public Employee(string username, string password)
    {
        Username = username;
        Password = password;
    }

    public override string ToString()
    {
        return $"Employee{{username='{Username}', password='{Password}', id={Id}}}";
    }
}