# this program matches a DNA sequence from an inputted file and matches it with a person from an inputted database file

import csv
from sys import argv, exit


# calculate the number of times a substring is repeated
def get_max_STR_repeats(string, substring):
    # array of the size of the string parameter
    max_repeats = [0] * len(string)
    # start at the end of string - the length of the substring and go back from there
    for i in range(len(string) - len(substring), -1, -1):
        # if the substring of length of the substring parameter starting at i equals the substring parameter
        if string[i:i + len(substring)] == substring:
            # if there is no more space in the string for another sequence
            if i + len(substring) > len(string) - 1:
                max_repeats[i] = 1
            else:
                # if the previous condition is not satisfied, the sequence will have been repeated 1 time + the number of times it was repeated before the current sequence started
                max_repeats[i] = 1 + max_repeats[i + len(substring)]

    # max value of the output array
    return max(max_repeats)

def print_match(reader, repeats):
    # do this for every person in the database
    for line in reader:
        name = line[0]
        # create array with the corresponding max consecutive repeats of each sub dna sequence being evaluated (remove name value), and convert them to an int
        seq_values = [int(val) for val in line[1:]]
        # compare values from the number of repeats from the txt with the ones provided in the database
        if seq_values == repeats:
            print(name) # if a match is found, print the name of the person match
            return
    print("No match")


def main():
    # if wrong number of inputs provided, end program
    if len(argv) != 3:
        print("USAGE python dna.py [CSVFILE] [TXTFILE]")
        exit(1)

    DATABASE_FILE = argv[1]
    SEQUENCE_FILE = argv[2]
    
    # open and read csv file
    with open(DATABASE_FILE) as database_file:
        reader = csv.reader(database_file) # stores an array for each row in the file, each array's first element is the name and next are the number of max consecutive STRs
        database_sequences = next(reader)[1:] # stores sequences in the database by taking all elements in the first row of the csv file besides the 'name'

        with open(SEQUENCE_FILE) as path_file:
            seq_string = path_file.read() # stores the dna sequence as a string
            sequences_max_repeats = [get_max_STR_repeats(seq_string, sequence) for sequence in database_sequences] # creates an array with the number of max consecutive repeats for each sub dna sequence being evaluated

        print_match(reader, sequences_max_repeats)

    
        

main()