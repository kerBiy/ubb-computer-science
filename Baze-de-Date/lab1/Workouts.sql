CREATE TABLE Workouts (
    WorkoutID INT PRIMARY KEY IDENTITY,
    WorkoutName NVARCHAR(100),
    Description NVARCHAR(255),
    DurationMinutes INT
);