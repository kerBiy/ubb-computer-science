from domain.entity import Location


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name

    def __save(self, locations: list) -> None:
        with open(self.__file_name, "w") as file:
            for location in locations:
                new_line = f"{location.id},{location.address},{location.city},{location.price},{location.warranty}\n"
                file.write(new_line)

    def filter(self, budget: float, city: str) -> list:
        locations = []

        with open(self.__file_name, "r") as file:
            for line in file:
                data = line.strip().split(",")

                location = Location(
                    int(data[0]),
                    data[1],
                    data[2],
                    float(data[3]),
                    float(data[4]),
                )

                if location.price <= budget and location.city == city:
                    locations.append(location)

        return locations

    def rent(self, id: int) -> Location:
        locations = []
        good_location = None

        with open(self.__file_name, "r") as file:
            for line in file:
                data = line.strip().split(",")

                location = Location(
                    int(data[0]),
                    data[1],
                    data[2],
                    float(data[3]),
                    float(data[4]),
                )

                if location.id == id:
                    good_location = location
                else:
                    locations.append(location)

        if good_location:
            self.__save(locations)

        return good_location
