-- 1. Găsește membrii care au participat la sesiunea ‘CrossFit Blitz’. (n-m, where)
SELECT m.Name AS MemberName, s.SessionName
FROM Members m
JOIN Member_Sessions ms ON m.MemberID = ms.MemberID
JOIN Sessions s ON ms.SessionID = s.SessionID
WHERE s.SessionName = 'CrossFit Blitz';

--2. Găsește toate sesiunile conduse de un antrenor și echipamentele folosite în acestea. (2+, where)
SELECT t.Name AS TrainerName, s.SessionName, e.EquipmentName
FROM Trainer_Sessions ts
JOIN Trainers t ON ts.TrainerID = t.TrainerID
JOIN Sessions s ON ts.SessionID = s.SessionID
JOIN Session_Equipment se ON s.SessionID = se.SessionID
JOIN Equipment e ON se.EquipmentID = e.EquipmentID
WHERE t.Name = 'Emma Lee';

-- 3. Găsește echipamentele distincte utilizate în sesiunile la care a participat un membru. (2+, distinct, where)
SELECT DISTINCT e.EquipmentName
FROM Equipment e
JOIN Session_Equipment se ON e.EquipmentID = se.EquipmentID
JOIN Sessions s ON se.SessionID = s.SessionID
JOIN Member_Sessions ms ON s.SessionID = ms.SessionID
JOIN Members m ON ms.MemberID = m.MemberID
WHERE m.Name = 'Jane Smith';

-- 4. Găsește antrenorii care conduc mai mult de 2 tipuri de antrenamente. (n-m, group by, having, ditinct)
SELECT t.Name AS TrainerName, COUNT(DISTINCT w.WorkoutName) AS WorkoutTypes
FROM Trainer_Workouts tw
JOIN Trainers t ON tw.TrainerID = t.TrainerID
JOIN Workouts w ON tw.WorkoutID = w.WorkoutID
GROUP BY t.Name
HAVING COUNT(DISTINCT w.WorkoutName) > 0;

-- 5. Găsește toate sesiunile la care a participat un anumit membru și echipamentele folosite. (2+, where)
SELECT m.Name AS MemberName, s.SessionName, e.EquipmentName
FROM Member_Sessions ms
JOIN Members m ON ms.MemberID = m.MemberID
JOIN Sessions s ON ms.SessionID = s.SessionID
JOIN Session_Equipment se ON s.SessionID = se.SessionID
JOIN Equipment e ON se.EquipmentID = e.EquipmentID
WHERE m.Name = 'John Doe';

-- 6. Numără membrii pentru fiecare plan de abonament, afișând doar planurile care au membri activi. (group by)
SELECT mp.PlanName, COUNT(m.MemberID) AS MemberCount
FROM Members m
JOIN MembershipPlans mp ON m.MembershipID = mp.MembershipID
GROUP BY mp.PlanName;

-- 7. Găsește membrii care au participat la cel puțin 3 sesiuni diferite și numărul de sesiuni la care au participat. (2+, group by, having)
SELECT m.Name AS MemberName, COUNT(s.SessionID) AS SessionCount
FROM Members m
JOIN Member_Sessions ms ON m.MemberID = ms.MemberID
JOIN Sessions s ON ms.SessionID = s.SessionID
GROUP BY m.Name
HAVING COUNT(s.SessionID) >= 0;

-- 8. Găsește toate sesiunile care au fost organizate după o anumită dată și numele antrenorului pentru fiecare sesiune. (2+, where)
SELECT s.SessionName, s.SessionDate, t.Name AS TrainerName
FROM Sessions s
JOIN Trainer_Sessions ts ON s.SessionID = ts.SessionID
JOIN Trainers t ON ts.TrainerID = t.TrainerID
WHERE s.SessionDate > '2024-10-01';

-- 9. Găsește numele antrenorilor care au participat la cel puțin o sesiune cu un echipament specific, afișând doar echipamentele distincte folosite. (2+, where)
SELECT DISTINCT t.Name AS TrainerName, e.EquipmentName
FROM Trainers t
JOIN Trainer_Sessions ts ON t.TrainerID = ts.TrainerID
JOIN Sessions s ON ts.SessionID = s.SessionID
JOIN Session_Equipment se ON s.SessionID = se.SessionID
JOIN Equipment e ON se.EquipmentID = e.EquipmentID
WHERE e.EquipmentName = 'Treadmill';

-- 10. Găsește echipamentele utilizate în mai mult de 2 sesiuni organizate de antrenori. (distinct, group by having, 2+)
SELECT e.EquipmentName, COUNT(DISTINCT s.SessionID) AS SessionCount
FROM Equipment e
JOIN Session_Equipment se ON e.EquipmentID = se.EquipmentID
JOIN Sessions s ON se.SessionID = s.SessionID
JOIN Trainer_Sessions ts ON s.SessionID = ts.SessionID
GROUP BY e.EquipmentName
HAVING COUNT(DISTINCT s.SessionID) > 0;