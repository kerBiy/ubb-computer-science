namespace Entities
{
    public class Team
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public Team(int id, string name)
        {
            Id = id;
            Name = name;
        }

        public override string ToString()
        {
            return $"{Id},{Name}";
        }
    }
}