import csv

types = {
    "Residential": 0,
    "Condo": 0,
    "Multi-Family": 0,
    "Unkown": 0
}

with open("Sacramentorealestatetransactions.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        type = row[7]
        types[type] += 1
    
for type in types:
    print(f"{type}: {types[type]}")