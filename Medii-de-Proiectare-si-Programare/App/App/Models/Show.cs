namespace App.Models;

public class Show : IIdentifiable<long>
{
    public long Id { get; set; }
    public string Artist { get; set; }
    public DateTime Date { get; set; }
    public string Location { get; set; }
    public int TotalSeats { get; set; }
    public int SoldSeats { get; set; }

    public Show(string artist, DateTime date, string location, int totalSeats, int soldSeats)
    {
        Artist = artist;
        Date = date;
        Location = location;
        TotalSeats = totalSeats;
        SoldSeats = soldSeats;
    }

    public override string ToString()
    {
        return $"Show{{artist='{Artist}', date={Date:yyyy-MM-dd}, location='{Location}', totalSeats={TotalSeats}, soldSeats={SoldSeats}, id={Id}}}";
    }
}