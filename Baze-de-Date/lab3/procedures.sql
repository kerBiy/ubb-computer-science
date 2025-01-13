USE Gym 

-------------------1--------------
CREATE PROCEDURE AlterColumnType 
AS
BEGIN
    ALTER TABLE Members ALTER COLUMN Name NVARCHAR(150); -- Alter column type
    PRINT 'Procedure AlterColumnType executed: Column type modified to NVARCHAR(150).';
END;

CREATE PROCEDURE RevertAlterColumnType
AS
BEGIN
    ALTER TABLE Members ALTER COLUMN Name NVARCHAR(100); -- Revert to original column type
    PRINT 'Procedure RevertAlterColumnType executed: Column type reverted to NVARCHAR(100).';
END;

-----------------------2-------------------------
CREATE PROCEDURE AddDefaultValue
AS
BEGIN
    ALTER TABLE Members 
    ADD CONSTRAINT DF_Members_StartDate DEFAULT GETDATE() FOR StartDate; -- Add default value for StartDate
    PRINT 'Procedure AddDefaultValue executed: Default value added for StartDate.';
END;

CREATE PROCEDURE RevertAddDefaultValue
AS
BEGIN
    ALTER TABLE Members
    DROP CONSTRAINT DF_Members_StartDate; -- Revert default value for StartDate
    PRINT 'Procedure RevertAddDefaultValue executed: Default value for StartDate removed.';
END;

---------------3----------------
CREATE PROCEDURE AddColumnAddress
AS
BEGIN
    ALTER TABLE Members ADD Address NVARCHAR(100); -- Add Address column
    PRINT 'Procedure AddColumnAddress executed: Address column added to Members.';
END;

CREATE PROCEDURE RevertAddColumnAddress
AS
BEGIN
    ALTER TABLE Members DROP COLUMN Address; -- Drop Address column
    PRINT 'Procedure RevertAddColumnAddress executed: Address column removed from Members.';
END;

--------------------4---------------
CREATE PROCEDURE CreateParentMemberTable
AS
BEGIN
    CREATE TABLE ParentMember (
        ParentID INT PRIMARY KEY IDENTITY(1,1),
        FullName NVARCHAR(100) NOT NULL,
        MemberID INT -- Relates to Members table
    );
    PRINT 'Procedure CreateParentMemberTable executed: ParentMember table created.';
END;

CREATE PROCEDURE DropParentMemberTable
AS
BEGIN
    DROP TABLE ParentMember; -- Drop ParentMember table
    PRINT 'Procedure DropParentMemberTable executed: ParentMember table dropped.';
END;

--------------------5--------------
CREATE PROCEDURE CreateForeignKey
AS
BEGIN
    ALTER TABLE ParentMember ADD CONSTRAINT FK_Parent_Member FOREIGN KEY (MemberID) REFERENCES Members(MemberID); -- Create foreign key
    PRINT 'Procedure CreateForeignKey executed: Foreign key created for ParentMember table.';
END;

CREATE PROCEDURE RevertCreateForeignKey
AS
BEGIN
    ALTER TABLE ParentMember DROP CONSTRAINT FK_Parent_Member; -- Drop foreign key
    PRINT 'Procedure RevertCreateForeignKey executed: Foreign key removed from ParentMember table.';
END;

CREATE TABLE Version(
 versionNo INT NOT NULL PRIMARY KEY,
 ModificationDate Date,
);

ALTER TABLE Version
ADD CONSTRAINT DF_ModificationDate DEFAULT GETDATE() FOR ModificationDate;

INSERT INTO Version(versionNo) VALUES(0);


------------Main procedure------------------
CREATE PROCEDURE UpdateVersion
	@new_version INT
AS
BEGIN
	IF @new_version IS NULL OR @new_version < 0 OR @new_version > 5
	BEGIN
		PRINT 'Invalid parameter for UpdateVersion.';
		RETURN;
	END;

	DECLARE @current_version INT;
	SELECT  @current_version = versionNo from Version;

	IF @current_version = @new_version
	BEGIN
		PRINT 'Table is already at the requested version.';
		RETURN;
	END;

	IF @current_version < @new_version
	BEGIN
		WHILE @current_version < @new_version
		BEGIN
			SET @current_version = @current_version + 1;

			IF @current_version = 1 EXEC AlterColumnType;
			IF @current_version = 2 EXEC AddDefaultValue;
			IF @current_version = 3 EXEC AddColumnAddress;
			IF @current_version = 4 EXEC CreateParentMemberTable;
			IF @current_version = 5 EXEC CreateForeignKey;

			PRINT CONCAT('UpdateVersion: Database updated to version ', @current_version, '.');
		END;
	END
	
	ELSE
	BEGIN
		WHILE @current_version > @new_version
		BEGIN
			IF @current_version = 1 EXEC RevertAlterColumnType;
			IF @current_version = 2 EXEC RevertAddDefaultValue;
			IF @current_version = 3 EXEC RevertAddColumnAddress;
			IF @current_version = 4 EXEC DropParentMemberTable;
			IF @current_version = 5 EXEC RevertCreateForeignKey;

			SET @current_version = @current_version - 1;
			PRINT CONCAT('UpdateVersion: Database reverted to version ', @current_version, '.');
		END;
	END;

	UPDATE Version
	SET versionNo = @current_version, ModificationDate = GETDATE();

	PRINT CONCAT ('Database version successfully updated to: ', @current_version);
END;

EXEC UpdateVersion 0;
SELECT * FROM Version;
