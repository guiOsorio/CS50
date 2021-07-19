# Program which classifies a sentence entered by the user according to its Coleman-Liau index
# The Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8,
# where L is the average number of letters per 100 words in the text,
# and S is the average number of sentences per 100 words in the text

def main():
    sentence = get_input()

    # Find number of letters
    num_letters = 0
    for c in sentence:
        if(c.isalpha()):
            num_letters += 1

    # Find number of words
    num_words = sentence.count(" ") + 1

    # Find number of sentences
    num_sentences = sentence.count(".") + sentence.count("!") + sentence.count("?")

    # Average number of letters per 100 words
    L = num_letters * (100 / num_words)

    # Average number of sentences per 100 words
    S = num_sentences * (100 / num_words)

    # Calculate grade
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    # Display grade to user
    if grade < 1:
        print("Before Grade 1")
    elif(grade >= 16):
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def get_input():
    sentence = input("Text: ")
    return sentence



main()