# Program that displays a # pyramid of a specified height, to resemble a Mario pyramid

def main():

    height = get_height()
    make(height)


def make(height):
    for i in range(1, height + 1):
        whites = height - i
        print(" " * whites, end="")
        print("#" * i, end="  ")
        print("#" * i)


def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if (height > 0 and height < 9):
                return height
        except ValueError:
            None


main()