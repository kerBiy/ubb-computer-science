-- Crearea bazei de date
CREATE DATABASE DistributieMonede;
GO

USE DistributieMonede;
GO

-- Crearea tabelelor
CREATE TABLE Persoane (
    ID_Persoana INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Gen CHAR(1) CHECK (Gen IN ('M', 'F')),
    Data_Nastere DATE
);

CREATE TABLE Copii (
    ID_Copil INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Varsta INT,
    ID_Parinte INT FOREIGN KEY REFERENCES Persoane(ID_Persoana)
);

CREATE TABLE Tipuri_De_Monede (
    ID_Tip_Moneda INT IDENTITY(1,1) PRIMARY KEY,
    Tara NVARCHAR(50),
    Element_Specific NVARCHAR(100)
);

CREATE TABLE Monede (
    ID_Moneda INT IDENTITY(1,1) PRIMARY KEY,
    Valoare FLOAT,
    Denumire NVARCHAR(50),
    ID_Tip_Moneda INT FOREIGN KEY REFERENCES Tipuri_De_Monede(ID_Tip_Moneda)
);

CREATE TABLE Persoane_Monede (
    ID_Persoana INT FOREIGN KEY REFERENCES Persoane(ID_Persoana),
    ID_Moneda INT FOREIGN KEY REFERENCES Monede(ID_Moneda),
    Numar INT,
    Utilitate NVARCHAR(100),
    PRIMARY KEY (ID_Persoana, ID_Moneda)
);

-- Procedura stocată
CREATE PROCEDURE AdaugaSauActualizeazaMoneda
    @ID_Persoana INT,
    @ID_Moneda INT,
    @Numar INT,
    @Utilitate NVARCHAR(100)
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM Persoane_Monede
        WHERE ID_Persoana = @ID_Persoana AND ID_Moneda = @ID_Moneda
    )
    BEGIN
        UPDATE Persoane_Monede
        SET Numar = @Numar, Utilitate = @Utilitate
        WHERE ID_Persoana = @ID_Persoana AND ID_Moneda = @ID_Moneda;
    END
    ELSE
    BEGIN
        INSERT INTO Persoane_Monede (ID_Persoana, ID_Moneda, Numar, Utilitate)
        VALUES (@ID_Persoana, @ID_Moneda, @Numar, @Utilitate);
    END
END;
GO

-- Crearea view-ului
CREATE VIEW MonedeCopii AS
SELECT 
    tm.Element_Specific AS Tip_Moneda,
    c.Nume AS Copil,
    c.Varsta AS Varsta
FROM Tipuri_De_Monede tm
JOIN Monede m ON tm.ID_Tip_Moneda = m.ID_Tip_Moneda
JOIN Persoane_Monede pm ON m.ID_Moneda = pm.ID_Moneda
JOIN Persoane p ON pm.ID_Persoana = p.ID_Persoana
JOIN Copii c ON c.ID_Parinte = p.ID_Persoana;
GO

-- Crearea funcției
CREATE FUNCTION PersoaneCuMonedaMinima (@ID_Moneda INT, @NumarMinim INT)
RETURNS NVARCHAR(MAX)
AS
BEGIN
    DECLARE @result NVARCHAR(MAX);

    SELECT @result = STRING_AGG(p.Nume, ', ')
    FROM Persoane p
    JOIN Persoane_Monede pm ON p.ID_Persoana = pm.ID_Persoana
    WHERE pm.ID_Moneda = @ID_Moneda AND pm.Numar >= @NumarMinim;

    RETURN @result;
END;
GO