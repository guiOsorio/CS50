def main():
    toupper = get_upper()
    toprint = get_word()
    num = get_num()
    return print_input(toupper, toprint, num)


def get_upper():
    done = False
    while done != True:
        ans = input("Upper or lowercase? ")
        if ans.lower() in ["u", "up", "upper", "uppercase"]:
            done = True
            return True
        elif ans.lower() in ["l", "low", "lower", "lowercase"]:
            done = True
            return False
        else:
            print("Input not valid. Please try again")
def get_word():
    toprint = input("What would you like to print? ")
    return toprint
def get_num():
    num = int(input("How many times would you like to print that word? "))
    return num

def print_input(toupper, toprint, num):
    if toupper:
        for i in range(1, num+1):
            print(f"{i} {toprint.upper()}")
    else:
        for i in range(1, num+1):
            print(f"{i} {toprint.lower()}")

main()