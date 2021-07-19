# This program identifies if the inputted number is a Visa, Mastercard, or AMEX credit card number
# Visa cards – Begin with a 4 and have 13 or 16 digits
# Mastercard cards – Begin with a 5 and has 16 digits
# American Express cards – Begin with a 3, followed by a 4 or a 7  has 15 digits

def main():
    card_num = get_input()
    
    if card_num[0] == "4"  and len(card_num) >= 13 and len(card_num) <= 16:
        print("VISA\n")
    elif card_num[0] == "5" and len(card_num) == 16:
        print("MASTERCARD\n")
    elif card_num[0] == "3" and (card_num[1] == "4" or card_num[1] == "7") and len(card_num) == 15:
        print("AMEX\n")
    else:
        print("INVALID\n")




def get_input():
    card_num = input("Number: ")
    return card_num

main()