# Se da data nașterii (zi/luna/an), determinați vârsta persoanei in zile.
from datetime import datetime

brithday = input("Enter Birthday (day/month/year): ")
brithday = datetime.strptime(brithday, "%d/%m/%Y")
now = datetime.now()
difference = now - brithday

print("The age in days is: ", difference.days)
