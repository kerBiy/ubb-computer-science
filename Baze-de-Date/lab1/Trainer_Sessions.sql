CREATE TABLE Trainer_Sessions (
    TrainerID INT,
    SessionID INT,
    PRIMARY KEY (TrainerID, SessionID),
    FOREIGN KEY (TrainerID) REFERENCES Trainers(TrainerID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID)
);