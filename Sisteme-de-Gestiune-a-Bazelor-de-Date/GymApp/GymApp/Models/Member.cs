namespace GymApp.Models;

public class Member
{
    public int MemberID { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
    public string PhoneNumber { get; set; }
    public int MembershipID { get; set; }
    public DateTime StartDate { get; set; }
}