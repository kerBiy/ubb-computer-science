namespace App.Models;

public class Ticket : IIdentifiable<long>
{
    public long Id { get; set; }
    public string Name { get; set; }
    public int NumberOfSeats { get; set; }
    public long ShowId { get; set; }

    public Ticket(string name, int numberOfSeats, long showId)
    {
        Name = name;
        NumberOfSeats = numberOfSeats;
        ShowId = showId;
    }

    public override string ToString()
    {
        return $"Ticket{{name='{Name}', numberOfSeats={NumberOfSeats}, showId={ShowId}, id={Id}}}";
    }
}