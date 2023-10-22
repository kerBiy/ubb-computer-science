class Car:
    def __init__(self, type, hp, color) -> None:
        self.type = type
        self.hp = hp
        self.color = color

    def printCar(self):
        print(f"The {self.type} is {self.color}")

    def addHp(self, val):
        self.hp += val


audi = Car("A8", 250, "blue")

audi.printCar()

audi.addHp(50)

print(audi.hp)
