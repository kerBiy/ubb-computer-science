--2. Găsește toate sesiunile conduse de un antrenor și echipamentele folosite în acestea. (2+, where)
SELECT t.Name AS TrainerName, s.SessionName, e.EquipmentName
FROM Trainer_Sessions ts
JOIN Trainers t ON ts.TrainerID = t.TrainerID
JOIN Sessions s ON ts.SessionID = s.SessionID
JOIN Session_Equipment se ON s.SessionID = se.SessionID
JOIN Equipment e ON se.EquipmentID = e.EquipmentID
WHERE t.Name = 'Emma Lee';