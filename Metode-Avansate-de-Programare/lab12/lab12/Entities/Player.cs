namespace Entities
{
    public class Player : Student
    {
        public int TeamId { get; set; }

        public Player(int id, string name, string school, int teamId)
            : base(id, name, school)
        {
            TeamId = teamId;
        }

        public override string ToString()
        {
            return $"{Id},{Name},{School},{TeamId}";
        }
    }
}