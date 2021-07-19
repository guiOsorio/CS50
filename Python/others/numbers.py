import sys

def numbers():
    numbers = [4, 6, 8, 2, 7, 5, 0]
    if 1 in numbers:
        print("Found")
        sys.exit(0)
    else:
        print("Not found")
        sys.exit(1)

def names():
    names = ["Gui", "Garrett", "Alex", "August"]
    if "Gui" in names:
        print("Found")
        sys.exit(0)
    else:
        print("Not found")
        sys.exit(1)

names()