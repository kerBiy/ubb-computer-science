using App.Models;
using App.Utils;
using App.Repositories;
using App.Services;
using App.Views;

namespace App;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();

        string dbName = "app.db";
        string dbPath = Path.Combine(FileSystem.AppDataDirectory, dbName);

        Console.WriteLine($"[APP INIT] DB path: {dbPath}");

        // Copiază fișierul dacă nu există deja
        if (!File.Exists(dbPath))
        {
            using var stream = FileSystem.OpenAppPackageFileAsync(dbName).Result;
            using var dest = File.Create(dbPath);
            stream.CopyTo(dest);
        }

        var db = new Database($"Data Source={dbPath}");

        var employeeRepo = new EmployeeRepository(db);
        var ticketRepo = new TicketRepository(db);
        var showRepo = new ShowRepository(db);
        var service = new Service(
            new ShowService(showRepo),
            new TicketService(ticketRepo, showRepo),
            new EmployeeService(employeeRepo)
        );

        MainPage = new NavigationPage(new LoginPage(service));

        // var employee = new Employee("admin", "admin") { Id = 1 };
        // MainPage = new NavigationPage(new MainPage(service, employee));
    }
}