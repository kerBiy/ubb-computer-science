USE GymManagementDB;
GO

-- Membership Plans (doar 3)
INSERT INTO MembershipPlans (PlanName, DurationMonths, Price) VALUES
('Basic', 3, 99.99),
('Premium', 6, 199.99),
('VIP', 12, 399.99);
GO

-- Members (mai mulți)
INSERT INTO Members (Name, Email, PhoneNumber, MembershipID, StartDate) VALUES
('John Doe', 'john@example.com', '555-1111', 1, '2024-01-01'),
('Jane Smith', 'jane@example.com', '555-2222', 2, '2024-02-01'),
('Alice Johnson', 'alice@example.com', '555-3333', 3, '2024-03-01'),
('Bob Williams', 'bob@example.com', '555-4444', 1, '2024-04-01'),
('Charlie Brown', 'charlie@example.com', '555-5555', 2, '2024-05-01'),
('Diana Prince', 'diana@example.com', '555-6666', 3, '2024-06-01'),
('Bruce Wayne', 'bruce@example.com', '555-7777', 1, '2024-07-01'),
('Clark Kent', 'clark@example.com', '555-8888', 2, '2024-08-01');
GO

-- Trainers (doar 3)
INSERT INTO Trainers (Name, Specialty, PhoneNumber, Email) VALUES
('David Anderson', 'Strength Training', '555-1010', 'david@example.com'),
('Emma Lee', 'Yoga', '555-2020', 'emma@example.com'),
('Sophia Clark', 'Cardio', '555-3030', 'sophia@example.com');
GO

-- Sessions (mai multe)
INSERT INTO Sessions (SessionName, SessionDate, SessionTime) VALUES
('Morning Yoga', '2024-10-01', '08:00'),
('CrossFit Blitz', '2024-10-02', '10:00'),
('Strength Mastery', '2024-10-03', '12:00'),
('Cardio Burn', '2024-10-04', '14:00'),
('Pilates Flow', '2024-10-05', '16:00'),
('Evening HIIT', '2024-10-06', '18:00'),
('Weekend Bootcamp', '2024-10-07', '09:00');
GO

-- Workouts (doar 3)
INSERT INTO Workouts (WorkoutName, Description, DurationMinutes) VALUES
('Yoga Stretch', 'Full body stretching yoga routine', 45),
('HIIT Cardio', 'High-intensity interval training', 30),
('Weight Lifting', 'Strength-focused workout', 60);
GO

-- Trainer_Sessions
INSERT INTO Trainer_Sessions (TrainerID, SessionID) VALUES
(2, 1), -- Emma -> Morning Yoga
(1, 3), -- David -> Strength Mastery
(3, 4), -- Sophia -> Cardio Burn
(1, 2), (3, 6), (2, 5);
GO

-- Member_Sessions
INSERT INTO Member_Sessions (MemberID, SessionID) VALUES
(1, 1), (2, 2), (3, 3), (4, 4), (5, 5), (6, 6), (7, 7), (8, 1);
GO

-- Trainer_Workouts
INSERT INTO Trainer_Workouts (TrainerID, WorkoutID) VALUES
(2, 1), -- Emma -> Yoga Stretch
(3, 2), -- Sophia -> HIIT
(1, 3); -- David -> Weight Lifting
GO

-- Equipment (mai multe)
INSERT INTO Equipment (EquipmentName, QuantityAvailable, Description) VALUES
('Yoga Mat', 30, 'Standard yoga mats'),
('Dumbbells', 20, 'Free weights'),
('Treadmill', 10, 'Running machine'),
('Pilates Ball', 15, 'For core and balance'),
('Kettlebell', 25, 'Functional weight'),
('Resistance Bands', 40, 'Strength bands'),
('Jump Rope', 35, 'Cardio tool'),
('Rowing Machine', 5, 'Full-body cardio');
GO

-- Session_Equipment (completat)
INSERT INTO Session_Equipment (SessionID, EquipmentID) VALUES
(1, 1), (2, 2), (3, 2), (4, 3), (5, 4), (6, 6), (7, 5), (7, 7);
GO