using App.Models;
using App.Repositories;

namespace App.Services;

public class TicketService
{
    private readonly ITicketRepository _ticketRepo;
    private readonly IShowRepository _showRepo;

    public TicketService(ITicketRepository ticketRepo, IShowRepository showRepo)
    {
        _ticketRepo = ticketRepo;
        _showRepo = showRepo;
    }

    public bool SellTicket(string buyerName, int numberOfSeats, Show show)
    {
        if (show.SoldSeats + numberOfSeats > show.TotalSeats)
            return false;

        var ticket = new Ticket(buyerName, numberOfSeats, show.Id);
        _ticketRepo.Save(ticket);

        show.SoldSeats += numberOfSeats;
        _showRepo.Update(show);

        return true;
    }
}