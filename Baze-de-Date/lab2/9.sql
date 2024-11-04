-- 9. Găsește numele antrenorilor care au participat la cel puțin o sesiune cu un echipament specific, afișând doar echipamentele distincte folosite. (2+, where)
SELECT DISTINCT t.Name AS TrainerName, e.EquipmentName
FROM Trainers t
JOIN Trainer_Sessions ts ON t.TrainerID = ts.TrainerID
JOIN Sessions s ON ts.SessionID = s.SessionID
JOIN Session_Equipment se ON s.SessionID = se.SessionID
JOIN Equipment e ON se.EquipmentID = e.EquipmentID
WHERE e.EquipmentName = 'Treadmill';