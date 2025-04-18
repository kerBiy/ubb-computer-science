using App.Models;

namespace App.Repositories;

public interface IEmployeeRepository : IRepository<long, Employee>
{
}