-- Validation Functions
CREATE OR ALTER FUNCTION ValidateQuantity(@Quantity INT)
RETURNS BIT
AS
BEGIN
    RETURN CASE WHEN @Quantity >= 0 THEN 1 ELSE 0 END;
END;
GO

CREATE OR ALTER FUNCTION ValidatePrice(@Price DECIMAL(10, 2))
RETURNS BIT
AS
BEGIN
    RETURN CASE WHEN @Price >= 0 THEN 1 ELSE 0 END;
END;
GO

CREATE OR ALTER FUNCTION ValidateTrainerID(@TrainerID INT)
RETURNS BIT
AS
BEGIN
    RETURN CASE WHEN @TrainerID > 0 THEN 1 ELSE 0 END;
END;
GO

CREATE OR ALTER FUNCTION ValidateWorkoutDuration(@Duration INT)
RETURNS BIT
AS
BEGIN
    RETURN CASE WHEN @Duration > 0 THEN 1 ELSE 0 END;
END;
GO

CREATE OR ALTER FUNCTION ValidateTrainerEmail(@Email NVARCHAR(100))
RETURNS BIT
AS
BEGIN
    RETURN CASE WHEN @Email LIKE '%@%.%' THEN 1 ELSE 0 END;
END;
GO

-- CRUD for Equipment table
CREATE OR ALTER PROCEDURE CRUD_Equipment
    @EquipmentName NVARCHAR(100),
    @QuantityAvailable INT,
    @Description NVARCHAR(255)
AS
BEGIN
    SET NOCOUNT ON;

    -- CREATE
    IF dbo.ValidateQuantity(@QuantityAvailable) = 1
    BEGIN
        DECLARE @EquipmentID INT;
        INSERT INTO Equipment (EquipmentName, QuantityAvailable, Description)
        VALUES (@EquipmentName, @QuantityAvailable, @Description);
        SET @EquipmentID = SCOPE_IDENTITY();
        PRINT 'INSERT operation completed';

        -- READ
        SELECT * FROM Equipment WHERE EquipmentID = @EquipmentID;
        PRINT 'SELECT operation completed';

        -- UPDATE
        UPDATE Equipment
        SET QuantityAvailable = QuantityAvailable + 10
        WHERE EquipmentID = @EquipmentID;
        PRINT 'UPDATE operation completed';

        -- DELETE
        DELETE FROM Equipment WHERE EquipmentID = @EquipmentID;
        PRINT 'DELETE operation completed';
    END
    ELSE
    BEGIN
        PRINT 'Validation failed for QuantityAvailable';
    END
END;
GO

-- CRUD for MembershipPlans table
CREATE OR ALTER PROCEDURE CRUD_MembershipPlans
    @PlanName NVARCHAR(100),
    @DurationMonths INT,
    @Price DECIMAL(10, 2)
AS
BEGIN
    SET NOCOUNT ON;

    -- CREATE
    IF dbo.ValidatePrice(@Price) = 1
    BEGIN
        DECLARE @MembershipID INT;
        INSERT INTO MembershipPlans (PlanName, DurationMonths, Price)
        VALUES (@PlanName, @DurationMonths, @Price);
        SET @MembershipID = SCOPE_IDENTITY();
        PRINT 'INSERT operation completed';

        -- READ
        SELECT * FROM MembershipPlans WHERE MembershipID = @MembershipID;
        PRINT 'SELECT operation completed';

        -- UPDATE
        UPDATE MembershipPlans
        SET Price = Price + 5
        WHERE MembershipID = @MembershipID;
        PRINT 'UPDATE operation completed';

        -- DELETE
        DELETE FROM MembershipPlans WHERE MembershipID = @MembershipID;
        PRINT 'DELETE operation completed';
    END
    ELSE
    BEGIN
        PRINT 'Validation failed for Price';
    END
END;
GO

-- CRUD for Trainer_Workouts table
CREATE OR ALTER PROCEDURE CRUD_TrainerWorkouts
    @TrainerID INT,
    @WorkoutID INT
AS
BEGIN
    SET NOCOUNT ON;

    -- CREATE
    IF dbo.ValidateTrainerID(@TrainerID) = 1
    BEGIN
        INSERT INTO Trainer_Workouts (TrainerID, WorkoutID)
        VALUES (@TrainerID, @WorkoutID);
        PRINT 'INSERT operation completed';

        -- READ
        SELECT * FROM Trainer_Workouts WHERE TrainerID = @TrainerID AND WorkoutID = @WorkoutID;
        PRINT 'SELECT operation completed';

        -- DELETE
        DELETE FROM Trainer_Workouts WHERE TrainerID = @TrainerID AND WorkoutID = @WorkoutID;
        PRINT 'DELETE operation completed';
    END
    ELSE
    BEGIN
        PRINT 'Validation failed for TrainerID or WorkoutID';
    END
END;
GO

-- CRUD for Workouts table
CREATE OR ALTER PROCEDURE CRUD_Workouts
    @WorkoutName NVARCHAR(100),
    @Description NVARCHAR(255),
    @DurationMinutes INT
AS
BEGIN
    SET NOCOUNT ON;

    -- CREATE
    IF dbo.ValidateWorkoutDuration(@DurationMinutes) = 1
    BEGIN
        DECLARE @WorkoutID INT;
        INSERT INTO Workouts (WorkoutName, Description, DurationMinutes)
        VALUES (@WorkoutName, @Description, @DurationMinutes);
        SET @WorkoutID = SCOPE_IDENTITY();
        PRINT 'INSERT operation completed';

        -- READ
        SELECT * FROM Workouts WHERE WorkoutID = @WorkoutID;
        PRINT 'SELECT operation completed';

        -- UPDATE
        UPDATE Workouts
        SET DurationMinutes = DurationMinutes + 5
        WHERE WorkoutID = @WorkoutID;
        PRINT 'UPDATE operation completed';

        -- DELETE
        DELETE FROM Workouts WHERE WorkoutID = @WorkoutID;
        PRINT 'DELETE operation completed';
    END
    ELSE
    BEGIN
        PRINT 'Validation failed for DurationMinutes';
    END
END;
GO

-- CRUD for Trainers table
CREATE OR ALTER PROCEDURE CRUD_Trainers
    @Name NVARCHAR(100),
    @Specialty NVARCHAR(100),
    @PhoneNumber NVARCHAR(15),
    @Email NVARCHAR(100)
AS
BEGIN
    SET NOCOUNT ON;

    -- CREATE
    IF dbo.ValidateTrainerEmail(@Email) = 1
    BEGIN
        DECLARE @TrainerID INT;
        INSERT INTO Trainers (Name, Specialty, PhoneNumber, Email)
        VALUES (@Name, @Specialty, @PhoneNumber, @Email);
        SET @TrainerID = SCOPE_IDENTITY();
        PRINT 'INSERT operation completed';

        -- READ
        SELECT * FROM Trainers WHERE TrainerID = @TrainerID;
        PRINT 'SELECT operation completed';

        -- UPDATE
        UPDATE Trainers
        SET Specialty = 'Updated Specialty'
        WHERE TrainerID = @TrainerID;
        PRINT 'UPDATE operation completed';

        -- DELETE
        DELETE FROM Trainers WHERE TrainerID = @TrainerID;
        PRINT 'DELETE operation completed';
    END
    ELSE
    BEGIN
        PRINT 'Validation failed for Email';
    END
END;
GO


-- Complex Views
CREATE OR ALTER VIEW View_EquipmentSummary AS
SELECT 
    EquipmentID,
    EquipmentName,
    QuantityAvailable,
    Description,
    QuantityAvailable * 1.1 AS ProjectedQuantity 
FROM Equipment;
GO

CREATE OR ALTER VIEW View_TrainerWorkouts AS
SELECT 
    T.TrainerID, 
    T.Name AS TrainerName, 
    W.WorkoutName, 
    W.DurationMinutes
FROM Trainers T
JOIN Trainer_Workouts TW ON T.TrainerID = TW.TrainerID
JOIN Workouts W ON TW.WorkoutID = W.WorkoutID;
GO

-- Example EXEC commands for CRUD procedures
PRINT 'Testing CRUD_Equipment Procedure:'
EXEC CRUD_Equipment 'Treadmill', 5, 'High-quality treadmill';
EXEC CRUD_Equipment 'Bicycle', -1, 'Stationary bike'; -- Should fail validation

PRINT 'Testing CRUD_MembershipPlans Procedure:'
EXEC CRUD_MembershipPlans 'Premium Plan', 12, 499.99;
EXEC CRUD_MembershipPlans 'Basic Plan', 6, -100; -- Should fail validation

PRINT 'Testing CRUD_TrainerWorkouts Procedure:'
EXEC CRUD_TrainerWorkouts 1, 2; -- Assuming TrainerID 1 and WorkoutID 2 exist
EXEC CRUD_TrainerWorkouts -1, 2; -- Should fail validation

PRINT 'Testing CRUD_Workouts Procedure:'
EXEC CRUD_Workouts 'Yoga', 'Relaxing yoga session', 45;
EXEC CRUD_Workouts 'Cardio Blast', 'High-intensity cardio', -30; -- Should fail validation

PRINT 'Testing CRUD_Trainers Procedure:'
EXEC CRUD_Trainers 'John Doe', 'Fitness', '1234567890', 'john.doe@example.com';
EXEC CRUD_Trainers 'Jane Smith', 'Yoga', '0987654321', 'invalid_email'; -- Should fail validation

-- Non-clustered Indexes for Views
CREATE NONCLUSTERED INDEX IDX_EquipmentName ON Equipment(EquipmentName);
CREATE NONCLUSTERED INDEX IDX_TrainerName ON Trainers(Name);

-- Example SELECT commands for views
PRINT 'Testing View_EquipmentSummary:'
SELECT * FROM View_EquipmentSummary;

PRINT 'Testing View_TrainerWorkouts:'
SELECT * FROM View_TrainerWorkouts;