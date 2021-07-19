people = {
    "Gui": "619-895-6596",
    "Mom": "969380728"
}

name = input("Name: ")

if name in people:
    number = people[name]
    print(f"{name}'s phone number is {number}")