-- 6. Numără membrii pentru fiecare plan de abonament, afișând doar planurile care au membri activi. (group by)
SELECT mp.PlanName, COUNT(m.MemberID) AS MemberCount
FROM Members m
JOIN MembershipPlans mp ON m.MembershipID = mp.MembershipID
GROUP BY mp.PlanName;