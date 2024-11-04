-- 10. Găsește echipamentele utilizate în mai mult de 2 sesiuni organizate de antrenori. (distinct, group by having, 2+)
SELECT e.EquipmentName, COUNT(DISTINCT s.SessionID) AS SessionCount
FROM Equipment e
JOIN Session_Equipment se ON e.EquipmentID = se.EquipmentID
JOIN Sessions s ON se.SessionID = s.SessionID
JOIN Trainer_Sessions ts ON s.SessionID = ts.SessionID
GROUP BY e.EquipmentName
HAVING COUNT(DISTINCT s.SessionID) > 0;