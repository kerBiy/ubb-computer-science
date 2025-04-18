using App.Models;
using App.Repositories;

namespace App.Services;

public class EmployeeService
{
    private readonly IEmployeeRepository _employeeRepo;

    public EmployeeService(IEmployeeRepository employeeRepo)
    {
        _employeeRepo = employeeRepo;
    }

    public Employee? Login(string username, string password)
    {
        Console.WriteLine("Login");
        foreach (var user in _employeeRepo.FindAll())
        {
            Console.WriteLine(user);    
        }
        return _employeeRepo.FindAll()
            .FirstOrDefault(e => e.Username == username && e.Password == password);
    }
}