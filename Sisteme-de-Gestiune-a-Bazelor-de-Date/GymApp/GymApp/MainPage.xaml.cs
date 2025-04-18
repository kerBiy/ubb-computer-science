using Microsoft.Maui.Controls;
using System;
using System.Data;
using System.Data.SqlClient;
using GymApp.Models;
using Microsoft.Data.SqlClient;

namespace GymApp;

public partial class MainPage : ContentPage
{
    private readonly string _connectionString =
        "Server=localhost,1433;Database=GymManagementDB;User Id=sa;Password=Str0ng!Passw0rd;TrustServerCertificate=True;";

    private DataTable _plansTable;
    private DataTable _membersTable;

    private int? _selectedPlanId;
    private int? _selectedMemberId;

    public MainPage()
    {
        InitializeComponent();
        LoadPlans();
    }

    private void LoadPlans()
    {
        using var connection = new SqlConnection(_connectionString);
        var adapter = new SqlDataAdapter("SELECT * FROM MembershipPlans", connection);
        var dataSet = new DataSet();
        adapter.Fill(dataSet, "Plans");

        _plansTable = dataSet.Tables["Plans"];
        PlansTable.ItemsSource = _plansTable.AsEnumerable()
            .Select(row => new MembershipPlan
            {
                MembershipID = Convert.ToInt32(row["MembershipID"]),
                PlanName = row["PlanName"].ToString(),
                DurationMonths = Convert.ToInt32(row["DurationMonths"]),
                Price = Convert.ToDecimal(row["Price"])
            })
            .ToList();
    }

    private void OnPlanSelected(object sender, SelectionChangedEventArgs e)
    {
        var selected = e.CurrentSelection.FirstOrDefault() as MembershipPlan;
        if (selected != null)
        {
            _selectedPlanId = selected.MembershipID;
            LoadMembers(_selectedPlanId.Value);
        }
    }

    private void LoadMembers(int membershipId)
    {
        using var connection = new SqlConnection(_connectionString);
        var adapter = new SqlDataAdapter("SELECT * FROM Members WHERE MembershipID = @id", connection);
        adapter.SelectCommand.Parameters.AddWithValue("@id", membershipId);

        var dataSet = new DataSet();
        adapter.Fill(dataSet, "Members");

        _membersTable = dataSet.Tables["Members"];
        MembersTable.ItemsSource = _membersTable.AsEnumerable()
            .Select(row => new Member
            {
                MemberID = Convert.ToInt32(row["MemberID"]),
                Name = row["Name"].ToString(),
                Email = row["Email"].ToString(),
                PhoneNumber = row["PhoneNumber"].ToString(),
                StartDate = Convert.ToDateTime(row["StartDate"])
            })
            .ToList();
    }

    private void OnMemberSelected(object sender, SelectionChangedEventArgs e)
    {
        var selected = e.CurrentSelection.FirstOrDefault() as Member;
        if (selected != null)
        {
            _selectedMemberId = selected.MemberID;
            NameEntry.Text = selected.Name;
            EmailEntry.Text = selected.Email;
            PhoneEntry.Text = selected.PhoneNumber;
            StartDatePicker.Date = selected.StartDate;
        }
    }

    private async void OnAddMember(object sender, EventArgs e)
    {
        if (!ValidateInputs(out string errorMessage))
        {
            await DisplayAlert("Validation Error", errorMessage, "OK");
            return;
        }

        try
        {
            using var connection = new SqlConnection(_connectionString);
            var checkCmd = new SqlCommand("SELECT COUNT(*) FROM Members WHERE Email = @Email", connection);
            checkCmd.Parameters.AddWithValue("@Email", EmailEntry.Text);
            connection.Open();
            int count = (int)checkCmd.ExecuteScalar();
            if (count > 0)
            {
                await DisplayAlert("Error", "A member with this email already exists.", "OK");
                return;
            }

            var cmd = new SqlCommand("INSERT INTO Members (Name, Email, PhoneNumber, MembershipID, StartDate) " +
                                     "VALUES (@Name, @Email, @Phone, @MembershipID, @StartDate)", connection);
            cmd.Parameters.AddWithValue("@Name", NameEntry.Text);
            cmd.Parameters.AddWithValue("@Email", EmailEntry.Text);
            cmd.Parameters.AddWithValue("@Phone", PhoneEntry.Text);
            cmd.Parameters.AddWithValue("@MembershipID", _selectedPlanId);
            cmd.Parameters.AddWithValue("@StartDate", StartDatePicker.Date);
            cmd.ExecuteNonQuery();

            await DisplayAlert("Success", "Member added successfully.", "OK");
            LoadMembers(_selectedPlanId.Value);
            ResetForm();
        }
        catch (Exception ex)
        {
            await DisplayAlert("Database Error", ex.Message, "OK");
        }
    }

    private async void OnUpdateMember(object sender, EventArgs e)
    {
        if (_selectedMemberId == null)
        {
            await DisplayAlert("Error", "No member selected to update.", "OK");
            return;
        }

        if (!ValidateInputs(out string errorMessage))
        {
            await DisplayAlert("Validation Error", errorMessage, "OK");
            return;
        }

        try
        {
            using var connection = new SqlConnection(_connectionString);
            var cmd = new SqlCommand("UPDATE Members SET Name = @Name, Email = @Email, PhoneNumber = @Phone, StartDate = @StartDate " +
                                     "WHERE MemberID = @MemberID", connection);
            cmd.Parameters.AddWithValue("@Name", NameEntry.Text);
            cmd.Parameters.AddWithValue("@Email", EmailEntry.Text);
            cmd.Parameters.AddWithValue("@Phone", PhoneEntry.Text);
            cmd.Parameters.AddWithValue("@StartDate", StartDatePicker.Date);
            cmd.Parameters.AddWithValue("@MemberID", _selectedMemberId);

            connection.Open();
            cmd.ExecuteNonQuery();

            await DisplayAlert("Success", "Member updated successfully.", "OK");
            LoadMembers(_selectedPlanId.Value);
            ResetForm();
        }
        catch (Exception ex)
        {
            await DisplayAlert("Database Error", ex.Message, "OK");
        }
    }

    private async void OnDeleteMember(object sender, EventArgs e)
    {
        if (_selectedMemberId == null)
        {
            await DisplayAlert("Error", "No member selected to delete.", "OK");
            return;
        }

        bool confirm = await DisplayAlert("Confirm", "Are you sure you want to delete this member?", "Yes", "No");
        if (!confirm) return;

        try
        {
            using var connection = new SqlConnection(_connectionString);
            var cmd = new SqlCommand("DELETE FROM Members WHERE MemberID = @MemberID", connection);
            cmd.Parameters.AddWithValue("@MemberID", _selectedMemberId);

            connection.Open();
            cmd.ExecuteNonQuery();

            await DisplayAlert("Success", "Member deleted successfully.", "OK");
            _selectedMemberId = null;
            LoadMembers(_selectedPlanId.Value);
            ResetForm();
        }
        catch (Exception ex)
        {
            await DisplayAlert("Database Error", ex.Message, "OK");
        }
    }

    private bool ValidateInputs(out string error)
    {
        error = "";

        if (string.IsNullOrWhiteSpace(NameEntry.Text) ||
            string.IsNullOrWhiteSpace(EmailEntry.Text) ||
            string.IsNullOrWhiteSpace(PhoneEntry.Text))
        {
            error = "All fields are required.";
            return false;
        }

        if (!EmailEntry.Text.Contains("@") || !EmailEntry.Text.Contains("."))
        {
            error = "Invalid email address.";
            return false;
        }

        return true;
    }

    private void ResetForm()
    {
        NameEntry.Text = string.Empty;
        EmailEntry.Text = string.Empty;
        PhoneEntry.Text = string.Empty;
        StartDatePicker.Date = DateTime.Today;
    }
}