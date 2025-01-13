using System;
using System.Globalization;
using Entities;
using Repositories;
using Services;

class Program
{
    static void Main(string[] args)
    {
        var teamRepo = new TeamRepository();
        var playerRepo = new PlayerRepository();
        var matchRepo = new MatchRepository();
        var activePlayerRepo = new ActivePlayerRepository();

        var service = new Service(teamRepo, playerRepo, matchRepo, activePlayerRepo);

        bool exit = false;

        while (!exit)
        {
            Console.Clear();
            Console.WriteLine("=== Jr. NBA League Management ===");
            Console.WriteLine("1. Display all players in a team");
            Console.WriteLine("2. Display active players of a team in a match");
            Console.WriteLine("3. Display matches in a date range");
            Console.WriteLine("4. Calculate match score");
            Console.WriteLine("5. Exit");
            Console.Write("Choose an option: ");

            string choice = Console.ReadLine();
            Console.Clear();

            switch (choice)
            {
                case "1":
                    DisplayPlayersByTeam(service);
                    break;
                case "2":
                    DisplayActivePlayersByTeamAndMatch(service);
                    break;
                case "3":
                    DisplayMatchesInDateRange(service);
                    break;
                case "4":
                    CalculateMatchScore(service);
                    break;
                case "5":
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Invalid option. Try again.");
                    break;
            }

            if (!exit)
            {
                Console.WriteLine("\nPress any key to continue...");
                Console.ReadKey();
            }
        }
    }

    static void DisplayPlayersByTeam(Service service)
    {
        Console.Write("Enter team name: ");
        string teamName = Console.ReadLine();

        var players = service.GetPlayersByTeamName(teamName);
        if (players.Count > 0)
        {
            Console.WriteLine($"Players in team {teamName}:");
            foreach (var player in players)
            {
                Console.WriteLine($"{player.Id}: {player.Name}, {player.School}");
            }
        }
        else
        {
            Console.WriteLine("No players found for this team.");
        }
    }

    static void DisplayActivePlayersByTeamAndMatch(Service service)
    {
        Console.Write("Enter team name: ");
        string teamName = Console.ReadLine();

        Console.Write("Enter match teams (e.g., 'Houston Rockets vs Miami Heat'): ");
        string matchTeams = Console.ReadLine();

        var players = service.GetActivePlayersByTeamAndMatch(teamName, matchTeams);
        if (players.Count > 0)
        {
            Console.WriteLine($"Active players for {teamName} in match {matchTeams}:");
            foreach (var player in players)
            {
                Console.WriteLine($"{player.PlayerId}: {player.PointsScored} points, {player.Role}");
            }
        }
        else
        {
            Console.WriteLine("No active players found.");
        }
    }

    static void DisplayMatchesInDateRange(Service service)
    {
        Console.Write("Enter start date (YYYY-MM-DD): ");
        DateTime startDate = DateTime.ParseExact(Console.ReadLine(), "yyyy-MM-dd", CultureInfo.InvariantCulture);

        Console.Write("Enter end date (YYYY-MM-DD): ");
        DateTime endDate = DateTime.ParseExact(Console.ReadLine(), "yyyy-MM-dd", CultureInfo.InvariantCulture);

        var matches = service.GetMatchesInDateRange(startDate, endDate);
        if (matches.Count > 0)
        {
            foreach (var match in matches)
            {
                string team1 = service.GetAllTeams().First(t => t.Id == match.Team1Id).Name; // Get team names
                string team2 = service.GetAllTeams().First(t => t.Id == match.Team2Id).Name;
                Console.WriteLine($"{team1} vs {team2} on {match.Date:yyyy-MM-dd}");
            }
        }
    }

    static void CalculateMatchScore(Service service)
    {
        Console.Write("Enter match teams (e.g., 'Houston Rockets vs Miami Heat'): ");
        string matchTeams = Console.ReadLine();

        int score = service.GetMatchScore(matchTeams);
        Console.WriteLine($"Total score for match {matchTeams}: {score} points.");
    }
}