-- 3. Găsește echipamentele distincte utilizate în sesiunile la care a participat un membru. (2+, distinct, where)
SELECT DISTINCT e.EquipmentName
FROM Equipment e
JOIN Session_Equipment se ON e.EquipmentID = se.EquipmentID
JOIN Sessions s ON se.SessionID = s.SessionID
JOIN Member_Sessions ms ON s.SessionID = ms.SessionID
JOIN Members m ON ms.MemberID = m.MemberID
WHERE m.Name = 'Jane Smith';