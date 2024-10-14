CREATE TABLE Member_Sessions (
    MemberID INT,
    SessionID INT,
    PRIMARY KEY (MemberID, SessionID),
    FOREIGN KEY (MemberID) REFERENCES Members(MemberID),
    FOREIGN KEY (SessionID) REFERENCES Sessions(SessionID)
);