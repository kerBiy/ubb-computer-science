using System.Data;
using App.Models;
using App.Utils;
using Microsoft.Data.Sqlite;

namespace App.Repositories;

public class ShowRepository : IShowRepository 
{
    private readonly Database _database;

    public ShowRepository(Database database)
    {
        _database = database;
    }

    public Show? FindOne(long id)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "SELECT * FROM shows WHERE id = @id";
        cmd.Parameters.AddWithValue("@id", id);

        using var reader = cmd.ExecuteReader();
        if (reader.Read())
        {
            return ExtractShow(reader);
        }

        return null;
    }

    public IEnumerable<Show> FindAll()
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "SELECT * FROM shows";

        using var reader = cmd.ExecuteReader();
        var list = new List<Show>();
        while (reader.Read())
        {
            list.Add(ExtractShow(reader));
        }

        return list;
    }

    public Show? Save(Show entity)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "INSERT INTO shows (artist, date, location, totalSeats, soldSeats) VALUES (@a, @d, @l, @t, @s)";
        cmd.Parameters.AddWithValue("@a", entity.Artist);
        cmd.Parameters.AddWithValue("@d", entity.Date);
        cmd.Parameters.AddWithValue("@l", entity.Location);
        cmd.Parameters.AddWithValue("@t", entity.TotalSeats);
        cmd.Parameters.AddWithValue("@s", entity.SoldSeats);

        cmd.ExecuteNonQuery();

        cmd.CommandText = "SELECT last_insert_rowid()";
        entity.Id = (long)(cmd.ExecuteScalar() ?? 0);

        return entity;
    }

    public Show? Delete(long id)
    {
        var existing = FindOne(id);
        if (existing == null) return null;

        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "DELETE FROM shows WHERE id = @id";
        cmd.Parameters.AddWithValue("@id", id);
        cmd.ExecuteNonQuery();

        return existing;
    }

    public Show? Update(Show entity)
    {
        using var con = _database.GetConnection();
        con.Open();

        using var cmd = con.CreateCommand();
        cmd.CommandText = "UPDATE shows SET artist = @a, date = @d, location = @l, totalSeats = @t, soldSeats = @s WHERE id = @id";
        cmd.Parameters.AddWithValue("@a", entity.Artist);
        cmd.Parameters.AddWithValue("@d", entity.Date);
        cmd.Parameters.AddWithValue("@l", entity.Location);
        cmd.Parameters.AddWithValue("@t", entity.TotalSeats);
        cmd.Parameters.AddWithValue("@s", entity.SoldSeats);
        cmd.Parameters.AddWithValue("@id", entity.Id);

        var rows = cmd.ExecuteNonQuery();
        return rows > 0 ? entity : null;
    }

    private Show ExtractShow(SqliteDataReader reader)
    {
        return new Show(
            reader.GetString(reader.GetOrdinal("artist")),
            reader.GetDateTime(reader.GetOrdinal("date")),
            reader.GetString(reader.GetOrdinal("location")),
            reader.GetInt32(reader.GetOrdinal("totalSeats")),
            reader.GetInt32(reader.GetOrdinal("soldSeats"))
        )
        {
            Id = reader.GetInt64(reader.GetOrdinal("id"))
        };
    }
}