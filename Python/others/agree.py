done = False


while done != True:
    c = input("Do you agree? ")

    if c.lower() in ["y", "yes"]:
        print("Agreed")
        done = True
    elif c.lower() in ["n", "no"]:
        print("Disagreed")
        done = True
    else:
        print("Value not recognized. Please try again")