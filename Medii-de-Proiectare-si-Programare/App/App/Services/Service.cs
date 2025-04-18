using App.Models;

namespace App.Services;

public class Service
{
    private readonly ShowService _showService;
    private readonly TicketService _ticketService;
    private readonly EmployeeService _employeeService;

    public Service(ShowService showService, TicketService ticketService, EmployeeService employeeService)
    {
        _showService = showService;
        _ticketService = ticketService;
        _employeeService = employeeService;
    }

    // === Employee related ===
    public Employee? Login(string username, string password)
    {
        return _employeeService.Login(username, password);
    }

    // === Show related ===
    public List<Show> GetAllShows()
    {
        return _showService.GetAllShows();
    }

    public List<Show> SearchShowsByDate(DateTime date)
    {
        return _showService.SearchByDate(date);
    }

    public void UpdateShow(Show show)
    {
        _showService.UpdateShow(show);
    }

    // === Ticket related ===
    public bool SellTicket(string buyerName, int nrSeats, Show show)
    {
        return _ticketService.SellTicket(buyerName, nrSeats, show);
    }
}