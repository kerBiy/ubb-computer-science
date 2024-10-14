CREATE TABLE Session_Equipment (
    SessionID INT,
    EquipmentID INT,
    PRIMARY KEY (SessionID, EquipmentID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID),
    FOREIGN KEY (EquipmentID) REFERENCES Equipment(EquipmentID)
);