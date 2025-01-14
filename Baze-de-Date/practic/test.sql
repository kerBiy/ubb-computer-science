CREATE DATABASE ExpozitiiDB
GO

USE ExpozitiiDB
GO

CREATE TABLE Expozitii (
    ID_Expozitie INT IDENTITY(1,1) PRIMARY KEY,
    Denumire NVARCHAR(50),
    Descriere NVARCHAR(250),
    Data_Inceput DATE,
    Data_Final DATE
);
GO

INSERT INTO Expozitii (Denumire, Descriere, Data_Inceput, Data_Final) VALUES ('Expozitie1', 'Descriere1', '2020-01-01', '2025-01-01')
INSERT INTO Expozitii (Denumire, Descriere, Data_Inceput, Data_Final) VALUES ('Expozitie2', 'Descriere2', '2020-01-01', '2025-01-01')
INSERT INTO Expozitii (Denumire, Descriere, Data_Inceput, Data_Final) VALUES ('Expozitie3', 'Descriere3', '2020-01-01', '2025-01-01')
SELECT * FROM Expozitii

CREATE TABLE Artisti (
    ID_Artist INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Prenume NVARCHAR(50),
    Gen CHAR(1) CHECK (Gen in ('M', 'F')),
    Anul_Nasterii INT
);
GO

INSERT INTO Artisti (Nume, Prenume, Gen, Anul_Nasterii) VALUES ('Nume1', 'Prenume1', 'M', 2000)
INSERT INTO Artisti (Nume, Prenume, Gen, Anul_Nasterii) VALUES ('Nume2', 'Prenume2', 'F', 2001)
INSERT INTO Artisti (Nume, Prenume, Gen, Anul_Nasterii) VALUES ('Nume3', 'Prenume3', 'M', 2003)
SELECT * FROM Artisti

CREATE TABLE Cani (
    ID_Cana INT IDENTITY(1,1) PRIMARY KEY,
    Denumire NVARCHAR(50),
    Forma NVARCHAR(50),
    An_Datare DATE,
    Valoare FLOAT,
    ID_Expozitie INT FOREIGN KEY REFERENCES Expozitii(ID_Expozitie),
    ID_Artist INT FOREIGN KEY REFERENCES Artisti(ID_Artist)
);
GO

CREATE TABLE Orase (
    ID_Oras INT IDENTITY(1,1) PRIMARY KEY,
    Denumire NVARCHAR(50),
    Judet NVARCHAR(50),
    Tara NVARCHAR(50)
);
GO

INSERT INTO Orase (Denumire, Judet, Tara) VALUES ('Cluj-Napoca', 'Cluj', 'Romanaia')
INSERT INTO Orase (Denumire, Judet, Tara) VALUES ('Suceava', 'Suceava', 'Romanaia')
INSERT INTO Orase (Denumire, Judet, Tara) VALUES ('Mangalia', 'Constanta', 'Romanaia')
INSERT INTO Orase (Denumire, Judet, Tara) VALUES ('Bucuresti', 'Ilfov', 'Romanaia')
SELECT * FROM Orase

CREATE TABLE Expozitii_Orase (
    ID_Expozitie INT FOREIGN KEY REFERENCES Expozitii(ID_Expozitie),
    ID_Oras INT FOREIGN KEY REFERENCES Orase(ID_Oras),
    PRIMARY KEY (ID_Expozitie, ID_Oras),
    Data_Inceput DATE,
    Data_Final DATE,
    Pret_Bilet FLOAT
)
GO

CREATE PROCEDURE AdaugaSauActualizeazaExpozitieOras
    @ExpozitieID INT,
    @OrasID INT,
    @DataInceput DATE,
    @DataFinal DATE,
    @PretBilet FLOAT
AS
BEGIN
    IF EXISTS (
        SELECT 1 
        FROM Expozitii_Orase
        WHERE ID_Expozitie = @ExpozitieID AND ID_Oras = @OrasID
    )
    BEGIN
        UPDATE Expozitii_Orase
        SET Data_Inceput = @DataInceput, Data_Final = @DataFinal, Pret_Bilet = @PretBilet
        WHERE ID_Expozitie = @ExpozitieID AND ID_Oras = @OrasID;
    END
    ELSE
    BEGIN
        INSERT INTO Expozitii_Orase (ID_Expozitie, ID_Oras, Data_Inceput, Data_Final, Pret_Bilet)
        VALUES (@ExpozitieID, @OrasID, @DataInceput, @DataFinal, @PretBilet);
    END
END;
GO

EXEC AdaugaSauActualizeazaExpozitieOras 1, 2, '2021-01-01', '2022-01-01', 20.99
EXEC AdaugaSauActualizeazaExpozitieOras 1, 3, '2022-01-01', '2023-01-01', 20.99
EXEC AdaugaSauActualizeazaExpozitieOras 1, 4, '2023-01-01', '2024-01-01', 90.99
EXEC AdaugaSauActualizeazaExpozitieOras 1, 1, '2020-01-01', '2021-01-01', 40.99
EXEC AdaugaSauActualizeazaExpozitieOras 2, 2, '2020-01-01', '2022-01-01', 30.99
EXEC AdaugaSauActualizeazaExpozitieOras 3, 1, '2024-01-01', '2025-01-01', 70.99
EXEC AdaugaSauActualizeazaExpozitieOras 3, 4, '2023-01-01', '2024-01-01', 30.99
SELECT * from Expozitii_Orase
GO

CREATE VIEW ExpozitiiMaximTreiOrase AS
SELECT 
    e.Denumire AS DenumireExpozitie,
    COUNT(o.ID_Oras) AS NumarOrase
FROM Expozitii e
JOIN Expozitii_Orase eo ON e.ID_Expozitie = eo.ID_Expozitie
JOIN Orase o ON eo.ID_Oras = o.ID_Oras
GROUP BY e.ID_Expozitie, e.Denumire
HAVING COUNT(o.ID_Oras) <= 3;
GO

SELECT * FROM ExpozitiiMaximTreiOrase