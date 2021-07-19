def first():
    s = input("Before: ")
    print("After: ", end="")
    print(s.upper())

def second():
    s = input("Before: ")
    print("After: ", end="")
    for c in s:
        print(c.upper(), end="")

second()