using App.Models;
using App.Services;
using App.Views;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace App.ViewModels;

public partial class LoginViewModel : ObservableObject
{
    private readonly Service _service;

    [ObservableProperty]
    private string _username;

    [ObservableProperty]
    private string _password;

    [ObservableProperty]
    private string _errorMessage;

    public LoginViewModel(Service service)
    {
        _service = service;
    }

    [RelayCommand]
    public void Login()
    {
        var employee = _service.Login(Username, Password);
        if (employee != null)
        {
            ErrorMessage = "Navigating to Employee Page";
            Application.Current.MainPage = new NavigationPage(new MainPage(_service, employee));        }
        else
        {
            ErrorMessage = "Invalid username or password.";
        }
    }
}