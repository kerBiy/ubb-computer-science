using System.Data;
using App.Models;
using App.Utils;
using Microsoft.Data.Sqlite;

namespace App.Repositories;

public class TicketRepository : ITicketRepository
{
    private readonly Database _database;

    public TicketRepository(Database database)
    {
        _database = database;
    }

    public Ticket? FindOne(long id)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "SELECT * FROM tickets WHERE id = @id";
        cmd.Parameters.AddWithValue("@id", id);

        using var reader = cmd.ExecuteReader();
        if (reader.Read())
        {
            return ExtractTicket(reader);
        }

        return null;
    }

    public IEnumerable<Ticket> FindAll()
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "SELECT * FROM tickets";

        using var reader = cmd.ExecuteReader();
        var list = new List<Ticket>();
        while (reader.Read())
        {
            list.Add(ExtractTicket(reader));
        }

        return list;
    }

    public Ticket? Save(Ticket entity)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "INSERT INTO tickets (name, numberOfSeats, showId) VALUES (@n, @s, @sid)";
        cmd.Parameters.AddWithValue("@n", entity.Name);
        cmd.Parameters.AddWithValue("@s", entity.NumberOfSeats);
        cmd.Parameters.AddWithValue("@sid", entity.ShowId);

        cmd.ExecuteNonQuery();

        cmd.CommandText = "SELECT last_insert_rowid()";
        entity.Id = (long)(cmd.ExecuteScalar() ?? 0);

        return entity;
    }

    public Ticket? Delete(long id)
    {
        var existing = FindOne(id);
        if (existing == null) return null;

        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "DELETE FROM tickets WHERE id = @id";
        cmd.Parameters.AddWithValue("@id", id);
        cmd.ExecuteNonQuery();

        return existing;
    }

    public Ticket? Update(Ticket entity)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "UPDATE tickets SET name = @n, numberOfSeats = @s, showId = @sid WHERE id = @id";
        cmd.Parameters.AddWithValue("@n", entity.Name);
        cmd.Parameters.AddWithValue("@s", entity.NumberOfSeats);
        cmd.Parameters.AddWithValue("@sid", entity.ShowId);
        cmd.Parameters.AddWithValue("@id", entity.Id);

        var rows = cmd.ExecuteNonQuery();
        return rows > 0 ? entity : null;
    }

    private Ticket ExtractTicket(SqliteDataReader reader)
    {
        return new Ticket(
            reader.GetString(reader.GetOrdinal("name")),
            reader.GetInt32(reader.GetOrdinal("numberOfSeats")),
            reader.GetInt64(reader.GetOrdinal("showId"))
        )
        {
            Id = reader.GetInt64(reader.GetOrdinal("id"))
        };
    }
}