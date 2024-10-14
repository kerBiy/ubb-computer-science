CREATE TABLE Trainer_Workouts (
    TrainerID INT,
    WorkoutID INT,
    PRIMARY KEY (TrainerID, WorkoutID),
    FOREIGN KEY (TrainerID) REFERENCES Trainers(TrainerID),
    FOREIGN KEY (WorkoutID) REFERENCES Workouts(WorkoutID)
);