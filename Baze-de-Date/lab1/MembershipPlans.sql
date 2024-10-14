CREATE TABLE MembershipPlans (
    MembershipID INT PRIMARY KEY IDENTITY,
    PlanName NVARCHAR(100),
    DurationMonths INT,
    Price DECIMAL(10, 2)
);