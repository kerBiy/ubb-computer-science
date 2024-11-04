-- 5. Găsește toate sesiunile la care a participat un anumit membru și echipamentele folosite. (2+, where)
SELECT m.Name AS MemberName, s.SessionName, e.EquipmentName
FROM Member_Sessions ms
JOIN Members m ON ms.MemberID = m.MemberID
JOIN Sessions s ON ms.SessionID = s.SessionID
JOIN Session_Equipment se ON s.SessionID = se.SessionID
JOIN Equipment e ON se.EquipmentID = e.EquipmentID
WHERE m.Name = 'John Doe';