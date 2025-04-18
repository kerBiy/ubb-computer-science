using App.Services;
using App.ViewModels;

namespace App.Views;

public partial class LoginPage : ContentPage
{
    public LoginPage(Service service)
    {
        InitializeComponent();
        BindingContext = new LoginViewModel(service);
    }
}