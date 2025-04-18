using System.Data;
using Microsoft.Data.Sqlite;
using App.Models;
using App.Utils;

namespace App.Repositories;

public class EmployeeRepository : IEmployeeRepository 
{
    private readonly Database _database;

    public EmployeeRepository(Database database)
    {
        _database = database;
    }

    public Employee? FindOne(long id)
    {
        using var con = _database.GetConnection();
        con.Open();
        using var cmd = con.CreateCommand();
        cmd.CommandText = "SELECT * FROM employees WHERE id = @id";
        cmd.Parameters.AddWithValue("@id", id);

        using var reader = cmd.ExecuteReader();
        return reader.Read() ? Extract(reader) : null;
    }

    public IEnumerable<Employee> FindAll()
    {
        var list = new List<Employee>();
        using var connection = _database.GetConnection();
        connection.Open();
        using var command = connection.CreateCommand();
        command.CommandText = "SELECT id, username, password FROM employees";

        using var reader = command.ExecuteReader();
        while (reader.Read())
        {
            var id = reader.GetInt64(0);
            var username = reader.GetString(1);
            var password = reader.GetString(2);

            var employee = new Employee(username, password) { Id = id };
            list.Add(employee);
        }

        return list;
    }

    public Employee? Save(Employee entity)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "INSERT INTO employees (username, password) VALUES (@u, @p)";
        cmd.Parameters.AddWithValue("@u", entity.Username);
        cmd.Parameters.AddWithValue("@p", entity.Password);
        cmd.ExecuteNonQuery();

        using var idCmd = con.CreateCommand();
        idCmd.CommandText = "SELECT last_insert_rowid();";
        var newId = (long)(idCmd.ExecuteScalar() ?? 0);

        entity.Id = newId;
        return entity;
    }

    public Employee? Delete(long id)
    {
        var emp = FindOne(id);
        if (emp == null) return null;

        using var con = _database.GetConnection();
        con.Open();
        using var cmd = con.CreateCommand();
        cmd.CommandText = "DELETE FROM employees WHERE id = @id";
        cmd.Parameters.AddWithValue("@id", id);
        cmd.ExecuteNonQuery();
        return emp;
    }

    public Employee? Update(Employee entity)
    {
        using var con = _database.GetConnection();
        con.Open();
        using var cmd = con.CreateCommand();
        cmd.CommandText = "UPDATE employees SET username = @u, password = @p WHERE id = @id";
        cmd.Parameters.AddWithValue("@u", entity.Username);
        cmd.Parameters.AddWithValue("@p", entity.Password);
        cmd.Parameters.AddWithValue("@id", entity.Id);
        var rows = cmd.ExecuteNonQuery();
        return rows > 0 ? entity : null;
    }

    private Employee Extract(SqliteDataReader reader)
    {
        return new Employee(
            reader.GetString(1),
            reader.GetString(2)
        )
        {
            Id = reader.GetInt64(0)
        };
    }
}