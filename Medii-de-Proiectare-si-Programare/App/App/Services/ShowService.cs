using App.Models;
using App.Repositories;

namespace App.Services;

public class ShowService
{
    private readonly IShowRepository _showRepo;

    public ShowService(IShowRepository showRepo)
    {
        _showRepo = showRepo;
    }

    public List<Show> GetAllShows()
    {
        return (List<Show>)_showRepo.FindAll();
    }

    public List<Show> SearchByDate(DateTime date)
    {
        return GetAllShows()
            .Where(show => show.Date.Date == date.Date)
            .ToList();
    }

    public void UpdateShow(Show show)
    {
        _showRepo.Update(show);
    }
}