-- 8. Găsește toate sesiunile care au fost organizate după o anumită dată și numele antrenorului pentru fiecare sesiune. (2+, where)
SELECT s.SessionName, s.SessionDate, t.Name AS TrainerName
FROM Sessions s
JOIN Trainer_Sessions ts ON s.SessionID = ts.SessionID
JOIN Trainers t ON ts.TrainerID = t.TrainerID
WHERE s.SessionDate > '2024-10-01';