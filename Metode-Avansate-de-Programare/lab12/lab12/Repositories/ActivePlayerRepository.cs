using Entities;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Repositories
{
    public class ActivePlayerRepository : IRepository<int, ActivePlayer>
    {
        private readonly string filePath = @"../../../Data/active_players.csv";

        public ActivePlayerRepository()
        {
            if (!File.Exists(filePath)) File.Create(filePath).Close();
        }

        public IEnumerable<ActivePlayer> FindAll()
        {
            return File.ReadAllLines(filePath)
                .Select(line => line.Split(','))
                .Select(parts => new ActivePlayer(
                    int.Parse(parts[0]),
                    int.Parse(parts[1]),
                    int.Parse(parts[2]),
                    parts[3]
                ))
                .ToList();
        }

        public ActivePlayer FindById(int id)
        {
            return FindAll().FirstOrDefault(p => p.PlayerId == id);
        }

        public void Add(ActivePlayer entity)
        {
            File.AppendAllText(filePath, $"{entity.PlayerId},{entity.MatchId},{entity.PointsScored},{entity.Role}\n");
        }

        public void Update(int id, ActivePlayer entity)
        {
            var players = FindAll().ToList();
            var index = players.FindIndex(p => p.PlayerId == id);
            if (index != -1)
            {
                players[index] = entity;
                SaveAll(players);
            }
        }

        public void Delete(int id)
        {
            var players = FindAll().Where(p => p.PlayerId != id).ToList();
            SaveAll(players);
        }

        private void SaveAll(IEnumerable<ActivePlayer> players)
        {
            File.WriteAllLines(filePath, players.Select(p => p.ToString()));
        }
    }
}