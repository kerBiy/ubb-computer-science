using Entities;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Repositories
{
    public class PlayerRepository : IRepository<int, Player>
    {
        private readonly string filePath = @"../../../Data/players.csv";

        public PlayerRepository()
        {
            if (!File.Exists(filePath)) File.Create(filePath).Close();
        }

        public IEnumerable<Player> FindAll()
        {
            return File.ReadAllLines(filePath)
                .Select(line => line.Split(','))
                .Select(parts => new Player(
                    int.Parse(parts[0]),
                    parts[1],
                    parts[2],
                    int.Parse(parts[3])
                ))
                .ToList();
        }

        public Player FindById(int id)
        {
            return FindAll().FirstOrDefault(p => p.Id == id);
        }

        public void Add(Player entity)
        {
            File.AppendAllText(filePath, $"{entity.Id},{entity.Name},{entity.School},{entity.TeamId}\n");
        }

        public void Update(int id, Player entity)
        {
            var players = FindAll().ToList();
            var index = players.FindIndex(p => p.Id == id);
            if (index != -1)
            {
                players[index] = entity;
                SaveAll(players);
            }
        }

        public void Delete(int id)
        {
            var players = FindAll().Where(p => p.Id != id).ToList();
            SaveAll(players);
        }

        private void SaveAll(IEnumerable<Player> players)
        {
            File.WriteAllLines(filePath, players.Select(p => p.ToString()));
        }
    }
}