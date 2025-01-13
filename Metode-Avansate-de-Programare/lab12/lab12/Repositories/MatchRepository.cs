using Entities;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Repositories
{
    public class MatchRepository : IRepository<int, Match>
    {
        private readonly string filePath = @"../../../Data/matches.csv";

        public MatchRepository()
        {
            if (!File.Exists(filePath)) File.Create(filePath).Close();
        }

        public IEnumerable<Match> FindAll()
        {
            return File.ReadAllLines(filePath)
                .Select(line => line.Split(','))
                .Select(parts => new Match(
                    int.Parse(parts[0]),
                    int.Parse(parts[1]),
                    int.Parse(parts[2]),
                    DateTime.Parse(parts[3])
                ))
                .ToList();
        }

        public Match FindById(int id)
        {
            return FindAll().FirstOrDefault(m => m.Id == id);
        }

        public void Add(Match entity)
        {
            File.AppendAllText(filePath, $"{entity.Id},{entity.Team1Id},{entity.Team2Id},{entity.Date:yyyy-MM-dd}\n");
        }

        public void Update(int id, Match entity)
        {
            var matches = FindAll().ToList();
            var index = matches.FindIndex(m => m.Id == id);
            if (index != -1)
            {
                matches[index] = entity;
                SaveAll(matches);
            }
        }

        public void Delete(int id)
        {
            var matches = FindAll().Where(m => m.Id != id).ToList();
            SaveAll(matches);
        }

        private void SaveAll(IEnumerable<Match> matches)
        {
            File.WriteAllLines(filePath, matches.Select(m => m.ToString()));
        }
    }
}