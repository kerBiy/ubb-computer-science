using Entities;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Repositories
{
    public class TeamRepository : IRepository<int, Team>
    {
        private readonly string filePath = @"../../../Data/teams.csv";

        public TeamRepository()
        {
            if (!File.Exists(filePath)) File.Create(filePath).Close();
        }

        public IEnumerable<Team> FindAll()
        {
            return File.ReadAllLines(filePath)
                .Select(line => line.Split(','))
                .Select(parts => new Team(int.Parse(parts[0]), parts[1]))
                .ToList();
        }

        public Team FindById(int id)
        {
            return FindAll().FirstOrDefault(t => t.Id == id);
        }

        public void Add(Team entity)
        {
            File.AppendAllText(filePath, $"{entity.Id},{entity.Name}\n");
        }

        public void Update(int id, Team entity)
        {
            var teams = FindAll().ToList();
            var index = teams.FindIndex(t => t.Id == id);
            if (index != -1)
            {
                teams[index] = entity;
                SaveAll(teams);
            }
        }

        public void Delete(int id)
        {
            var teams = FindAll().Where(t => t.Id != id).ToList();
            SaveAll(teams);
        }

        private void SaveAll(IEnumerable<Team> teams)
        {
            File.WriteAllLines(filePath, teams.Select(t => t.ToString()));
        }
    }
}