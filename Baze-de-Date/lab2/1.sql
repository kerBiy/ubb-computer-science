-- 1. Găsește membrii care au participat la sesiunea ‘CrossFit Blitz’. (n-m, where)
SELECT m.Name AS MemberName, s.SessionName
FROM Members m
JOIN Member_Sessions ms ON m.MemberID = ms.MemberID
JOIN Sessions s ON ms.SessionID = s.SessionID
WHERE s.SessionName = 'CrossFit Blitz';