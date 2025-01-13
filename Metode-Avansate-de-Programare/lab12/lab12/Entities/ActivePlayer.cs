namespace Entities
{
    public class ActivePlayer
    {
        public int PlayerId { get; set; }
        public int MatchId { get; set; }
        public int PointsScored { get; set; }
        public string Role { get; set; } 

        public ActivePlayer(int playerId, int matchId, int pointsScored, string role)
        {
            PlayerId = playerId;
            MatchId = matchId;
            PointsScored = pointsScored;
            Role = role;
        }

        public override string ToString()
        {
            return $"{PlayerId},{MatchId},{PointsScored},{Role}";
        }
    }
}