from domain.domain import Student, Subject, Grade
import random


class Random:
    @classmethod
    def set_students(cls) -> dict:
        return {
            111: Student(111, "Balta Alex"),
            112: Student(112, "Timu Iustin"),
            113: Student(113, "Daniel Marius"),
            114: Student(114, "Daniel Petrica"),
            115: Student(115, "Darie Ciprian"),
            116: Student(116, "David Aneci"),
        }

    @classmethod
    def set_subjects(cls) -> dict:
        return {
            111: Subject(111, "Geografie", "Balta Alex"),
            112: Subject(112, "Termometru", "Timu Iustin"),
            113: Subject(113, "Geometrie", "Daniel Marius"),
            114: Subject(114, "Daniel", "Daniel Petrica"),
            115: Subject(115, "Calculus", "Darie Ciprian"),
            116: Subject(116, "Mate", "David Aneci"),
        }

    @classmethod
    def set_grades(cls) -> dict:
        return {
            1: Grade(1, 111, 115, 7.5),
            2: Grade(2, 112, 115, 8.5),
            3: Grade(3, 113, 115, 2.5),
            4: Grade(4, 114, 115, 9.5),
            5: Grade(5, 115, 115, 7),
            6: Grade(6, 116, 115, 7.69),
            7: Grade(7, 114, 112, 2),
            8: Grade(8, 111, 111, 2.5),
            9: Grade(9, 111, 113, 2),
        }

    @classmethod
    def students(cls) -> dict:
        output = {}

        for i in range(3):
            random_student = cls.get_student()
            output[random_student.id] = random_student

        return output

    @classmethod
    def get_student(cls) -> Student:
        names = [
            "Alex Balta",
            "Darie Cirpian",
            "Maria Ioana",
            "David Aneci",
            "Balan Darius",
            "Iustin Timu",
            "Nechiforeasa Andrei",
            "Timu Andrei",
            "Balta Claudiu",
        ]

        random.shuffle(names)
        name = names[0]

        id_student = random.randint(1, 1000)

        return Student(id_student, name)

    @classmethod
    def subjects(cls) -> dict:
        output = {}

        for i in range(3):
            random_subject = cls.get_subject()
            output[random_subject.id] = random_subject

        return output

    @classmethod
    def get_subject(cls) -> Subject:
        profs = [
            "Diri Diriga",
            "Doamana Diriginta",
            "Taran Luminita",
            "Mariuc Izabela",
            "Chizblua Istava",
            "Gabi Mircea",
        ]
        subjects = [
            "Mate matica",
            "Caluculs",
            "Analiza",
            "Algebra",
            "Geometrie",
            "Fundamente",
        ]
        random.shuffle(profs)
        prof = profs[0]

        random.shuffle(subjects)
        subject = subjects[0]

        id_subject = random.randint(1, 1000)

        return Subject(id_subject, subject, prof)
