-- Creare VIEW-uri
CREATE OR ALTER VIEW view_sessions
AS
SELECT * 
FROM Sessions
WHERE SessionDate > DATEADD(MONTH, 1, GETDATE()) AND SessionDate < DATEADD(MONTH, 2, GETDATE());
GO

CREATE OR ALTER VIEW view_members
AS
SELECT Name, Email, PhoneNumber 
FROM Members
WHERE PhoneNumber LIKE '072%';
GO

CREATE OR ALTER VIEW view_sessions_group
AS
SELECT S.SessionDate, COUNT(*) AS NrParticipants
FROM Sessions S
INNER JOIN Member_Sessions MS ON S.SessionID = MS.SessionID
GROUP BY S.SessionDate;
GO

-- Inserare în tabelul Views
INSERT INTO Views(Name) VALUES
('view_sessions'),
('view_members'),
('view_sessions_group');
GO

-- Inserare în tabelul Tables
INSERT INTO Tables(Name) VALUES
('Sessions'),
('Members'),
('Member_Sessions');
GO

-- Proceduri de ștergere
CREATE OR ALTER PROCEDURE del_Sessions
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Member_Sessions;
    DELETE FROM Sessions;
END;
GO

CREATE OR ALTER PROCEDURE del_Members
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Member_Sessions;
    DELETE FROM Members;
END;
GO

CREATE OR ALTER PROCEDURE del_Member_Sessions
AS
BEGIN
    SET NOCOUNT ON;
    DELETE FROM Member_Sessions;
END;
GO

-- Proceduri de inserare
CREATE OR ALTER PROCEDURE ins_Sessions
@NoOfRows INT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @sessionName NVARCHAR(100);
    DECLARE @sessionDate DATE;
    DECLARE @sessionTime TIME;
    DECLARE @n INT = 0;

    WHILE @n < @NoOfRows
    BEGIN
        SET @sessionName = 'Session ' + CONVERT(NVARCHAR(10), @n);
        SET @sessionDate = DATEADD(DAY, @n, GETDATE());
        SET @sessionTime = '10:00:00';

        INSERT INTO Sessions (SessionName, SessionDate, SessionTime)
        VALUES (@sessionName, @sessionDate, @sessionTime);

        SET @n = @n + 1;
    END;

    PRINT 'S-au inserat ' + CONVERT(VARCHAR(10), @NoOfRows) + ' valori în Sessions';
END;

GO

CREATE OR ALTER PROCEDURE ins_Members
@NoOfRows INT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @name NVARCHAR(150);
    DECLARE @email NVARCHAR(100);
    DECLARE @phone NVARCHAR(15);
    DECLARE @membershipID INT = 1; -- Exemplu implicit
    DECLARE @startDate DATE = GETDATE();
    DECLARE @n INT = 0;

    WHILE @n < @NoOfRows
    BEGIN
        SET @name = 'Member ' + CONVERT(NVARCHAR(10), @n);
        SET @email = 'member' + CONVERT(NVARCHAR(10), @n) + '@example.com';
        SET @phone = '07' + RIGHT('00000000' + CAST(CAST(FLOOR(RAND() * 100000000) AS INT) AS NVARCHAR(8)), 8);

        INSERT INTO Members (Name, Email, PhoneNumber, MembershipID, StartDate)
        VALUES (@name, @email, @phone, @membershipID, @startDate);

        SET @n = @n + 1;
    END;

    PRINT 'S-au inserat ' + CONVERT(VARCHAR(10), @NoOfRows) + ' valori în Members';
END;
GO

CREATE OR ALTER PROCEDURE ins_Member_Sessions
@NoOfRows INT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @memberID INT;
    DECLARE @sessionID INT;
    DECLARE @n INT = 0;

    IF NOT EXISTS (SELECT 1 FROM Members) OR NOT EXISTS (SELECT 1 FROM Sessions)
    BEGIN
        PRINT 'Nu există date suficiente în tabelele Members sau Sessions.';
        RETURN;
    END;

    DECLARE member_cursor CURSOR FOR SELECT MemberID FROM Members;
    DECLARE session_cursor CURSOR FOR SELECT SessionID FROM Sessions;

    OPEN member_cursor;
    OPEN session_cursor;

    FETCH NEXT FROM member_cursor INTO @memberID;
    FETCH NEXT FROM session_cursor INTO @sessionID;

    WHILE @n < @NoOfRows AND @@FETCH_STATUS = 0
    BEGIN
        INSERT INTO Member_Sessions (MemberID, SessionID)
        VALUES (@memberID, @sessionID);

        SET @n = @n + 1;

        FETCH NEXT FROM session_cursor INTO @sessionID;
        IF @@FETCH_STATUS <> 0
        BEGIN
            CLOSE session_cursor;
            OPEN session_cursor;
            FETCH NEXT FROM session_cursor INTO @sessionID;
        END;

        FETCH NEXT FROM member_cursor INTO @memberID;
        IF @@FETCH_STATUS <> 0
        BEGIN
            CLOSE member_cursor;
            OPEN member_cursor;
            FETCH NEXT FROM member_cursor INTO @memberID;
        END;
    END;

    CLOSE member_cursor;
    DEALLOCATE member_cursor;

    CLOSE session_cursor;
    DEALLOCATE session_cursor;

    PRINT 'S-au inserat ' + CONVERT(VARCHAR(10), @NoOfRows) + ' statistici în tabelul Member_Sessions';
END;
GO

INSERT INTO Tests(Name) VALUES
('test_SESSIONS'),
('test_MEMBERS'),
('test_MEMBER_SESSIONS')
GO

SELECT * FROM Tables
Select * from Tests

INSERT INTO TestTables(TestID,TableID,NoOfRows,Position) VALUES
(1,1,100,1),
(2,2,100,2),
(3,3,100,3)
GO

INSERT INTO TestViews(TestID,ViewID) VALUES
(1,1),
(2,2),
(3,3)
GO

CREATE OR ALTER PROCEDURE inserare_testgen
@idTest INT
AS
BEGIN
	DECLARE @numeTest NVARCHAR(50) = (SELECT T.Name FROM Tests T WHERE T.TestID = @idTest);
	DECLARE @numeTabela NVARCHAR(50);
	DECLARE @NoOfRows INT;
	DECLARE @procedura NVARCHAR(50);

	SELECT @numeTabela = Tab.Name, @NoOfRows = Test.NoOfRows FROM TestTables Test
	INNER JOIN Tables Tab ON Test.TableID = Tab.TableID
	WHERE Test.TestID = @idTest

	SET @procedura = N'ins_' + @numeTabela;
	EXECUTE @procedura @NoOfRows;
END
GO

CREATE OR ALTER PROCEDURE stergere_testgen
@idTest INT
AS
BEGIN
	DECLARE @numeTest NVARCHAR(50) = (SELECT T.Name FROM Tests T WHERE T.TestID = @idTest);
	DECLARE @numeTabela NVARCHAR(50);
	DECLARE @NoOfRows INT;
	DECLARE @procedura NVARCHAR(50);

	SELECT @numeTabela = Tab.Name, @NoOfRows = Test.NoOfRows FROM TestTables Test
	INNER JOIN Tables Tab ON Test.TableID = Tab.TableID
	WHERE Test.TestID = @idTest

	SET @procedura = N'del_' + @numeTabela;
	EXECUTE @procedura;
END
go

CREATE OR ALTER PROCEDURE view_testgen
@idTest INT
AS
BEGIN
	DECLARE @viewName NVARCHAR(50) = 
		(SELECT V.Name FROM Views V
		INNER JOIN TestViews TV ON TV.ViewID = V.ViewID
		WHERE TV.TestID = @idTest);
    
    PRINT @viewName;

	DECLARE @comanda NVARCHAR(55) = 
		N'SELECT * FROM ' + @viewName;
	
	EXECUTE (@comanda);
END
go

CREATE OR ALTER PROCEDURE run_test
@idTest INT
AS
BEGIN
	DECLARE @startTime DATETIME;
	DECLARE @interTime DATETIME;
	DECLARE @endTime DATETIME;

	SET @startTime = GETDATE();
	
	EXECUTE stergere_testgen @idTest;
	EXECUTE inserare_testgen @idTest;
	
	SET @interTime = GETDATE();
	
	EXECUTE view_testgen @idTest;

	SET @endTime = GETDATE();

	-- var pt insert
	DECLARE @testName NVARCHAR(50) =
		(SELECT T.Name FROM Tests T WHERE T.TestID = @idTest);
	INSERT INTO TestRuns VALUES (@testName, @startTime, @endTime);

	DECLARE @viewID INT =
		(SELECT V.ViewID FROM Views V
		INNER JOIN TestViews TV ON TV.ViewID = V.ViewID
		WHERE TV.TestID = @idTest);
	DECLARE @tableID INT =
		(SELECT TB.TableID FROM Tests T
		INNER JOIN TestTables TT ON T.TestID = TT.TestID
		INNER JOIN Tables TB ON TB.TableID = TT.TableID
		WHERE T.TestID = @idTest)
	DECLARE @testRunID INT = 
		(SELECT TOP 1 T.TestRunID FROM TestRuns T
		WHERE T.Description = @testName
		ORDER BY T.TestRunID DESC);
	
	INSERT INTO TestRunTables VALUES (@testRunID, @tableID, @startTime, @interTime);
	INSERT INTO TestRunViews VALUES (@testRunID, @viewID, @interTime, @endTime);

	PRINT CHAR(10) + '---> TEST COMPLETAT CU SUCCES IN ' + 
		 CONVERT(VARCHAR(10), DATEDIFF(millisecond, @startTime, @endTime)) +
		 ' milisecunde. <---'
END
GO

DELETE FROM Tables WHERE TableID > 3
GO
DELETE FROM Views WHERE ViewID > 3
GO
DELETE FROM Tests WHERE TestID > 3
GO

DELETE FROM Member_Sessions
GO
DELETE FROM Members
GO
DELETE FROM Sessions
GO

exec run_test 1

SELECT * FROM TestRuns
SELECT * FROM TestRunTables
SELECT * FROM TestRunViews

DELETE FROM TestRuns
GO