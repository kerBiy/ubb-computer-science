from domain.domain import Student, Subject
import random


class Random:
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
