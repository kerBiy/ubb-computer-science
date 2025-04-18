using App.Models;
using App.Services;
using App.ViewModels;

namespace App.Views;

public partial class MainPage : ContentPage
{
    public MainPage(Service service, Employee employee)
    {
        InitializeComponent();
        BindingContext = new MainViewModel(service, employee);
    }
}