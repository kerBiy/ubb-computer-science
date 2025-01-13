using System;
using System.Collections.Generic;
using System.Linq;
using Entities;
using Repositories;

namespace Services
{
    public class Service
    {
        private readonly IRepository<int, Team> teamRepo;
        private readonly IRepository<int, Player> playerRepo;
        private readonly IRepository<int, Match> matchRepo;
        private readonly IRepository<int, ActivePlayer> activePlayerRepo;

        public delegate bool PlayerFilter(Player player);

        public Service(
            IRepository<int, Team> teamRepo,
            IRepository<int, Player> playerRepo,
            IRepository<int, Match> matchRepo,
            IRepository<int, ActivePlayer> activePlayerRepo)
        {
            this.teamRepo = teamRepo;
            this.playerRepo = playerRepo;
            this.matchRepo = matchRepo;
            this.activePlayerRepo = activePlayerRepo;
        }
        
        public List<Team> GetAllTeams()
        {
            return teamRepo.FindAll().ToList();
        }

        // 1. Get all players in a specific team (by team name) using delegate
        public List<Player> GetPlayersByTeamName(string teamName)
        {
            var team = teamRepo.FindAll().FirstOrDefault(t => t.Name == teamName); // LINQ
            if (team == null) return new List<Player>();

            PlayerFilter filter = player => player.TeamId == team.Id;

            return playerRepo.FindAll()
                             .Where(p => filter(p))  
                             .OrderBy(p => p.Name)  
                             .ToList();
        }

        // 2. Get all active players in a specific match for a team (by team name)
        public List<ActivePlayer> GetActivePlayersByTeamAndMatch(string teamName, string matchTeams)
        {
            var team = teamRepo.FindAll().FirstOrDefault(t => t.Name == teamName);
            if (team == null) return new List<ActivePlayer>();

            var match = matchRepo.FindAll()
                .FirstOrDefault(m =>
                    matchTeams.Contains(teamRepo.FindById(m.Team1Id)?.Name) &&
                    matchTeams.Contains(teamRepo.FindById(m.Team2Id)?.Name));

            if (match == null) return new List<ActivePlayer>();

            var players = playerRepo.FindAll().Where(p => p.TeamId == team.Id).Select(p => p.Id);
            return activePlayerRepo.FindAll()
                                   .Where(ap => ap.MatchId == match.Id && players.Contains(ap.PlayerId)) // LINQ
                                   .ToList();
        }

        // 3. Get all matches within a specific date range
        public List<Match> GetMatchesInDateRange(DateTime startDate, DateTime endDate)
        {
            return matchRepo.FindAll()
                            .Where(m => m.Date >= startDate && m.Date <= endDate) // LINQ
                            .ToList();
        }

        // 4. Calculate total score for a match (by team names)
        public int GetMatchScore(string matchTeams)
        {
            var match = matchRepo.FindAll()
                .FirstOrDefault(m =>
                    matchTeams.Contains(teamRepo.FindById(m.Team1Id)?.Name) &&
                    matchTeams.Contains(teamRepo.FindById(m.Team2Id)?.Name));

            if (match == null) return 0;

            return activePlayerRepo.FindAll()
                                   .Where(ap => ap.MatchId == match.Id) // LINQ
                                   .Sum(ap => ap.PointsScored);       // LINQ Aggregation
        }
    }
}