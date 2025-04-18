namespace App.Utils;

using System;
using System.Data;
using Microsoft.Data.Sqlite;

public class Database
{
    private static SqliteConnection? _instance;
    private readonly string _connectionString;

    public Database(string connectionString)
    {
        _connectionString = connectionString;
    }

    private SqliteConnection CreateNewConnection()
    {
        Console.WriteLine("Creating new SQLite connection...");
        var connection = new SqliteConnection(_connectionString);
        connection.Open();
        return connection;
    }

    public SqliteConnection GetConnection()
    {
        Console.WriteLine($"[DB DEBUG] Connecting to: {_connectionString}");
        return new SqliteConnection(_connectionString);
    }
}