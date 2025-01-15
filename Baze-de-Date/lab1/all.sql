CREATE TABLE Equipment (
    EquipmentID INT PRIMARY KEY IDENTITY,
    EquipmentName NVARCHAR(100),
    QuantityAvailable INT,
    Description NVARCHAR(255)
);

CREATE TABLE Member_Sessions (
    MemberID INT,
    SessionID INT,
    PRIMARY KEY (MemberID, SessionID),
    FOREIGN KEY (MemberID) REFERENCES Members(MemberID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID)
);

CREATE TABLE Members (
    MemberID INT PRIMARY KEY IDENTITY,
    Name NVARCHAR(100),
    Email NVARCHAR(100) UNIQUE,
    PhoneNumber NVARCHAR(15),
    MembershipID INT,
    StartDate DATE,
    FOREIGN KEY (MembershipID) REFERENCES MembershipPlans(MembershipID)
);

CREATE TABLE MembershipPlans (
    MembershipID INT PRIMARY KEY IDENTITY,
    PlanName NVARCHAR(100),
    DurationMonths INT,
    Price DECIMAL(10, 2)
);

CREATE TABLE Session_Equipment (
    SessionID INT,
    EquipmentID INT,
    PRIMARY KEY (SessionID, EquipmentID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID),
    FOREIGN KEY (EquipmentID) REFERENCES Equipment(EquipmentID)
);

CREATE TABLE Session_Equipment (
    SessionID INT,
    EquipmentID INT,
    PRIMARY KEY (SessionID, EquipmentID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID),
    FOREIGN KEY (EquipmentID) REFERENCES Equipment(EquipmentID)
);

CREATE TABLE Sessions (
    SessionID INT PRIMARY KEY IDENTITY,
    SessionName NVARCHAR(100),
    SessionDate DATE,
    SessionTime TIME
);

CREATE TABLE Trainer_Sessions (
    TrainerID INT,
    SessionID INT,
    PRIMARY KEY (TrainerID, SessionID),
    FOREIGN KEY (TrainerID) REFERENCES Trainers(TrainerID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID)
);

CREATE TABLE Trainer_Workouts (
    TrainerID INT,
    WorkoutID INT,
    PRIMARY KEY (TrainerID, WorkoutID),
    FOREIGN KEY (TrainerID) REFERENCES Trainers(TrainerID),
    FOREIGN KEY (WorkoutID) REFERENCES Workouts(WorkoutID)
);

CREATE TABLE Trainers (
    TrainerID INT PRIMARY KEY IDENTITY,
    Name NVARCHAR(100),
    Specialty NVARCHAR(100),
    PhoneNumber NVARCHAR(15),
    Email NVARCHAR(100) UNIQUE
);

CREATE TABLE Workouts (
    WorkoutID INT PRIMARY KEY IDENTITY,
    WorkoutName NVARCHAR(100),
    Description NVARCHAR(255),
    DurationMinutes INT
);