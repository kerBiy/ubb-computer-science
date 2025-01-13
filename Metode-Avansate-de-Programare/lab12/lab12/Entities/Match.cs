namespace Entities
{
    public class Match
    {
        public int Id { get; set; }
        public int Team1Id { get; set; }
        public int Team2Id { get; set; }
        public DateTime Date { get; set; }

        public Match(int id, int team1Id, int team2Id, DateTime date)
        {
            Id = id;
            Team1Id = team1Id;
            Team2Id = team2Id;
            Date = date;
        }

        public override string ToString()
        {
            return $"{Id},{Team1Id},{Team2Id},{Date:yyyy-MM-dd}";
        }
    }
}