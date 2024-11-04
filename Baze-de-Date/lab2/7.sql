-- 7. Găsește membrii care au participat la cel puțin 3 sesiuni diferite și numărul de sesiuni la care au participat. (2+, group by, having)
SELECT m.Name AS MemberName, COUNT(s.SessionID) AS SessionCount
FROM Members m
JOIN Member_Sessions ms ON m.MemberID = ms.MemberID
JOIN Sessions s ON ms.SessionID = s.SessionID
GROUP BY m.Name
HAVING COUNT(s.SessionID) >= 0;