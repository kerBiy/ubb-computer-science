-- Crearea bazei de date
CREATE DATABASE ExploratoriUnivers;
GO

USE ExploratoriUnivers;
GO

-- Crearea tabelelor
CREATE TABLE Planete (
    ID_Planeta INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Descriere NVARCHAR(MAX),
    Distanta_Soare FLOAT,
    Distanta_Pamant FLOAT
);

CREATE TABLE Sateliti (
    ID_Satelit INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Marime FLOAT,
    Specific NVARCHAR(MAX),
    ID_Planeta INT FOREIGN KEY REFERENCES Planete(ID_Planeta)
);

CREATE TABLE Roci (
    ID_Roca INT IDENTITY(1,1) PRIMARY KEY,
    Denumire NVARCHAR(50),
    Durata NVARCHAR(50),
    Aparitie NVARCHAR(MAX)
);

CREATE TABLE Planete_Roci (
    ID_Planeta INT FOREIGN KEY REFERENCES Planete(ID_Planeta),
    ID_Roca INT FOREIGN KEY REFERENCES Roci(ID_Roca),
    PRIMARY KEY (ID_Planeta, ID_Roca)
);

CREATE TABLE Exploratori (
    ID_Explorator INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Gen CHAR(1) CHECK (Gen IN ('M', 'F')),
    Data_Nastere DATE
);

CREATE TABLE Misiuni (
    ID_Misiune INT IDENTITY(1,1) PRIMARY KEY,
    ID_Explorator INT FOREIGN KEY REFERENCES Exploratori(ID_Explorator),
    ID_Planeta INT FOREIGN KEY REFERENCES Planete(ID_Planeta),
    Data DATE,
    Descriere NVARCHAR(MAX)
);

-- Procedura stocată
CREATE PROCEDURE AdaugaSauActualizeazaMisiune
    @ExploratorID INT,
    @PlanetaID INT,
    @DataMisiune DATE,
    @DescriereMisiune NVARCHAR(MAX)
AS
BEGIN
    IF EXISTS (
        SELECT 1 
        FROM Misiuni
        WHERE ID_Explorator = @ExploratorID AND ID_Planeta = @PlanetaID
    )
    BEGIN
        UPDATE Misiuni
        SET Data = @DataMisiune, Descriere = @DescriereMisiune
        WHERE ID_Explorator = @ExploratorID AND ID_Planeta = @PlanetaID;
    END
    ELSE
    BEGIN
        INSERT INTO Misiuni (ID_Explorator, ID_Planeta, Data, Descriere)
        VALUES (@ExploratorID, @PlanetaID, @DataMisiune, @DescriereMisiune);
    END
END;
GO

-- Crearea view-ului
CREATE VIEW PlaneteSateliti AS
SELECT 
    p.Nume AS Planeta,
    s.Nume AS Satelit,
    s.Marime AS Marime_Satelit,
    s.Specific AS Specific_Satelit
FROM Planete p
LEFT JOIN Sateliti s ON p.ID_Planeta = s.ID_Planeta;
GO

-- Crearea funcției
CREATE FUNCTION ExploratoriPePlanetaCuRoca (@RocaID INT)
RETURNS NVARCHAR(MAX)
AS
BEGIN
    DECLARE @result NVARCHAR(MAX);

    SELECT @result = STRING_AGG(e.Nume, ', ')
    FROM Exploratori e
    JOIN Misiuni m ON e.ID_Explorator = m.ID_Explorator
    JOIN Planete_Roci pr ON m.ID_Planeta = pr.ID_Planeta
    WHERE pr.ID_Roca = @RocaID;

    RETURN @result;
END;
GO