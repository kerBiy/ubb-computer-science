CREATE TABLE Trainers (
    TrainerID INT PRIMARY KEY IDENTITY,
    Name NVARCHAR(100),
    Specialty NVARCHAR(100),
    PhoneNumber NVARCHAR(15),
    Email NVARCHAR(100) UNIQUE
);