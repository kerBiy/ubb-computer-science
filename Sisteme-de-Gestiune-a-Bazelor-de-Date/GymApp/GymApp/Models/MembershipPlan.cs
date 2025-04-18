namespace GymApp.Models;

public class MembershipPlan
{
    public int MembershipID { get; set; }
    public string PlanName { get; set; }
    public int DurationMonths { get; set; }
    public decimal Price { get; set; }
}