CREATE TABLE Members (
    MemberID INT PRIMARY KEY IDENTITY,
    Name NVARCHAR(100),
    Email NVARCHAR(100) UNIQUE,
    PhoneNumber NVARCHAR(15),
    MembershipID INT,
    StartDate DATE,
    FOREIGN KEY (MembershipID) REFERENCES MembershipPlans(MembershipID)
);