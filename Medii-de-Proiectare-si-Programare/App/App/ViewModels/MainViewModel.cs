using System.Collections.ObjectModel;
using App.Models;
using App.Services;
using App.Views;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace App.ViewModels;

public partial class MainViewModel : ObservableObject
{
    private readonly Service _service;
    private readonly Employee _loggedInEmployee;

    [ObservableProperty]
    private ObservableCollection<Show> shows = new();

    [ObservableProperty]
    private DateTime? filterDate;

    [ObservableProperty]
    private string employeeUsername;

    [ObservableProperty]
    private string buyerName;

    [ObservableProperty]
    private int numberOfSeats;

    [ObservableProperty]
    private Show? selectedShow;

    [ObservableProperty]
    private string message;

    public MainViewModel(Service service, Employee employee)
    {
        _service = service;
        _loggedInEmployee = employee;
        EmployeeUsername = $"Logged in as: {employee.Username}";
        LoadShows();
    }

    private void LoadShows()
    {
        var showList = _service.GetAllShows();
        Shows = new ObservableCollection<Show>(showList);
    }

    [RelayCommand]
    private void FilterByDate()
    {
        if (FilterDate != null)
        {
            var filtered = _service.SearchShowsByDate(FilterDate.Value);
            Shows = new ObservableCollection<Show>(filtered);
        }
    }

    [RelayCommand]
    private void ClearFilter()
    {
        FilterDate = null;
        LoadShows();
    }

    [RelayCommand]
    private void Logout()
    {
        Application.Current.MainPage = new NavigationPage(new LoginPage(_service));
    }

    [RelayCommand]
    private async Task BuyTicket()
    {
        if (SelectedShow == null)
        {
            await Application.Current.MainPage.DisplayAlert("Error", "Please select a show.", "OK");
            return;
        }

        if (string.IsNullOrWhiteSpace(BuyerName))
        {
            await Application.Current.MainPage.DisplayAlert("Error", "Please enter buyer name.", "OK");
            return;
        }

        if (NumberOfSeats <= 0)
        {
            await Application.Current.MainPage.DisplayAlert("Error", "Please enter a valid number of seats.", "OK");
            return;
        }

        var success = _service.SellTicket(BuyerName, NumberOfSeats, SelectedShow);
        if (success)
        {
            await Application.Current.MainPage.DisplayAlert("Success", "Ticket purchased successfully!", "OK");
            BuyerName = string.Empty;
            NumberOfSeats = 0;
            LoadShows(); // Refresh pentru update locuri rămase
        }
        else
        {
            await Application.Current.MainPage.DisplayAlert("Error", "Not enough seats available.", "OK");
        }
    }
}