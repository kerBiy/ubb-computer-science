-- 4. Găsește antrenorii care conduc mai mult de 2 tipuri de antrenamente. (n-m, group by, having, ditinct)
SELECT t.Name AS TrainerName, COUNT(DISTINCT w.WorkoutName) AS WorkoutTypes
FROM Trainer_Workouts tw
JOIN Trainers t ON tw.TrainerID = t.TrainerID
JOIN Workouts w ON tw.WorkoutID = w.WorkoutID
GROUP BY t.Name
HAVING COUNT(DISTINCT w.WorkoutName) > 0;