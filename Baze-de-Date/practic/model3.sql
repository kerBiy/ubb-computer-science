-- Crearea bazei de date
CREATE DATABASE MagazineProduse;
GO

USE MagazineProduse;
GO

-- Crearea tabelelor
CREATE TABLE Magazine (
    ID_Magazin INT IDENTITY(1,1) PRIMARY KEY,
    Denumire NVARCHAR(100),
    An_Deschidere INT,
    ID_Locatie INT
);

CREATE TABLE Locatii (
    ID_Locatie INT IDENTITY(1,1) PRIMARY KEY,
    Localitate NVARCHAR(50),
    Strada NVARCHAR(100),
    Numar INT,
    Cod_Postal NVARCHAR(10)
);

CREATE TABLE Clienti (
    ID_Client INT IDENTITY(1,1) PRIMARY KEY,
    Nume NVARCHAR(50),
    Prenume NVARCHAR(50),
    Gen CHAR(1) CHECK (Gen IN ('M', 'F')),
    Data_Nastere DATE
);

CREATE TABLE Produse_Favorite (
    ID_Produs INT IDENTITY(1,1) PRIMARY KEY,
    Denumire NVARCHAR(100),
    Pret FLOAT,
    Reducere FLOAT CHECK (Reducere BETWEEN 0 AND 100),
    ID_Client INT FOREIGN KEY REFERENCES Clienti(ID_Client)
);

CREATE TABLE Cumparaturi (
    ID_Cumparare INT IDENTITY(1,1) PRIMARY KEY,
    ID_Client INT FOREIGN KEY REFERENCES Clienti(ID_Client),
    ID_Magazin INT FOREIGN KEY REFERENCES Magazine(ID_Magazin),
    Data_Cumpararii DATE,
    Pret_Achitat FLOAT
);

-- Procedura stocată
CREATE PROCEDURE AdaugaSauActualizeazaCumparare
    @ID_Client INT,
    @ID_Magazin INT,
    @Data_Cumpararii DATE,
    @Pret_Achitat FLOAT
AS
BEGIN
    IF EXISTS (
        SELECT 1 
        FROM Cumparaturi
        WHERE ID_Client = @ID_Client AND ID_Magazin = @ID_Magazin
    )
    BEGIN
        UPDATE Cumparaturi
        SET Data_Cumpararii = @Data_Cumpararii, Pret_Achitat = @Pret_Achitat
        WHERE ID_Client = @ID_Client AND ID_Magazin = @ID_Magazin;
    END
    ELSE
    BEGIN
        INSERT INTO Cumparaturi (ID_Client, ID_Magazin, Data_Cumpararii, Pret_Achitat)
        VALUES (@ID_Client, @ID_Magazin, @Data_Cumpararii, @Pret_Achitat);
    END
END;
GO

-- Crearea view-ului
CREATE VIEW ClientiProduseFavorite AS
SELECT 
    c.Nume + ' ' + c.Prenume AS Client,
    COUNT(p.ID_Produs) AS Numar_Produse_Favorite
FROM Clienti c
LEFT JOIN Produse_Favorite p ON c.ID_Client = p.ID_Client
GROUP BY c.ID_Client, c.Nume, c.Prenume
HAVING COUNT(p.ID_Produs) <= 3;
GO