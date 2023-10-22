# Determina o data calendaristica (sub forma an, luna, zi) pornind de la doua numere întregi care reprezintă anul si numărul de ordine al zilei in anul respectiv.
from datetime import datetime, timedelta

year = int(input("Enter the year: "))
order_num = int(input("Enter the order of the day: "))

date = datetime(year, 1, 1)
date += timedelta(days=order_num - 1)
print(f"The date is: {date.day}/{date.month}/{date.year}")
