using App.Models;

namespace App.Repositories;

public interface ITicketRepository : IRepository<long, Ticket>
{
}