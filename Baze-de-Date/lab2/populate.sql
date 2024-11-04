-- Insert into MembershipPlans
INSERT INTO MembershipPlans (PlanName, DurationMonths, Price) VALUES
('Basic', 3, 99.99),
('Premium', 6, 199.99),
('VIP', 12, 399.99),
('Student', 3, 79.99),
('Family', 12, 349.99);

-- Insert into Members
INSERT INTO Members (Name, Email, PhoneNumber, MembershipID, StartDate) VALUES
('John Doe', 'john@example.com', '555-1111', 1, '2024-01-01'),
('Jane Smith', 'jane@example.com', '555-2222', 2, '2024-02-01'),
('Alice Johnson', 'alice@example.com', '555-3333', 3, '2024-03-01'),
('Bob Williams', 'bob@example.com', '555-4444', 1, '2024-04-01'),
('Charlie Brown', 'charlie@example.com', '555-5555', 4, '2024-05-01');

-- Insert into Trainers
INSERT INTO Trainers (Name, Specialty, PhoneNumber, Email) VALUES
('David Anderson', 'Strength Training', '555-6666', 'david@example.com'),
('Emma Lee', 'Yoga', '555-7777', 'emma@example.com'),
('Sophia Clark', 'Cardio', '555-8888', 'sophia@example.com'),
('Michael Davis', 'CrossFit', '555-9999', 'michael@example.com'),
('Olivia Wilson', 'Pilates', '555-0000', 'olivia@example.com');

-- Insert into Sessions
INSERT INTO Sessions (SessionName, SessionDate, SessionTime) VALUES
('Morning Yoga', '2024-10-01', '08:00'),
('CrossFit Blitz', '2024-10-02', '10:00'),
('Strength Mastery', '2024-10-03', '12:00'),
('Cardio Burn', '2024-10-04', '14:00'),
('Pilates Flow', '2024-10-05', '16:00');

-- Insert into Workouts
INSERT INTO Workouts (WorkoutName, Description, DurationMinutes) VALUES
('Yoga Stretch', 'Full body stretching yoga routine', 45),
('HIIT Cardio', 'High-intensity interval training for cardio', 30),
('Weight Lifting', 'Strength-focused weight lifting session', 60),
('Core Blaster', 'Core strength training exercises', 50),
('Pilates Basics', 'Pilates fundamentals for beginners', 40);

-- Insert into Trainer_Sessions (Many-to-Many Relationship)
INSERT INTO Trainer_Sessions (TrainerID, SessionID) VALUES
(2, 1), -- Emma -> Morning Yoga
(4, 2), -- Michael -> CrossFit Blitz
(1, 3), -- David -> Strength Mastery
(3, 4), -- Sophia -> Cardio Burn
(5, 5); -- Olivia -> Pilates Flow

-- Insert into Member_Sessions (Many-to-Many Relationship)
INSERT INTO Member_Sessions (MemberID, SessionID) VALUES
(1, 1), -- John -> Morning Yoga
(2, 2), -- Jane -> CrossFit Blitz
(3, 3), -- Alice -> Strength Mastery
(4, 4), -- Bob -> Cardio Burn
(5, 5); -- Charlie -> Pilates Flow

-- Insert into Trainer_Workouts (Many-to-Many Relationship)
INSERT INTO Trainer_Workouts (TrainerID, WorkoutID) VALUES
(2, 1), -- Emma -> Yoga Stretch
(3, 2), -- Sophia -> HIIT Cardio
(1, 3), -- David -> Weight Lifting
(4, 4), -- Michael -> Core Blaster
(5, 5); -- Olivia -> Pilates Basics

-- Insert into Equipment
INSERT INTO Equipment (EquipmentName, QuantityAvailable, Description) VALUES
('Yoga Mat', 30, 'Standard yoga mats for sessions'),
('Dumbbells', 20, 'Various weights for strength training'),
('Treadmill', 10, 'Cardio equipment'),
('Pilates Ball', 15, 'Stability balls for Pilates'),
('Kettlebell', 25, 'Weights for functional training');

-- Insert into Session_Equipment (Many-to-Many Relationship)
INSERT INTO Session_Equipment (SessionID, EquipmentID) VALUES
(1, 1), -- Morning Yoga -> Yoga Mat
(2, 2), -- CrossFit Blitz -> Dumbbells
(3, 2), -- Strength Mastery -> Dumbbells
(4, 3), -- Cardio Burn -> Treadmill
(5, 4); -- Pilates Flow -> Pilates Ball