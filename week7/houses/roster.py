import sys
from cs50 import SQL

db = SQL("sqlite:///students.db")

def main(argv):

    # Checks if the user typed the right number of arguments if not exit's the program
    if len(argv) != 2:
        sys.exit("Usage: python roster.py house")

    # Create a variable from the argument
    hpHouse = argv[1]

    #Copy the dataBase into a list with a dictionary for each row of the DB, and already ordered by Last and first name.
    dbCopy = db.execute("SELECT * FROM students ORDER BY last, first")

    #   Loop that iterates trough the list, dictionary by dictionary and checks if the input is the same as the
    # the dict "house" value we are currently in.
    # If its true then I check if this dict "middle" value is "None", if so I don't print the first/last name and birth
    # but not the middle name if its false I print all the names of the current dictionary and the birth.
    # I use print with format so I can add "born" and ","

    for row in dbCopy:
        if hpHouse == row['house']:
            if row['middle'] == None:

                print(f"{row['first']} {row['last']}, born {row['birth']}")
            else:
                print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")

# Calling the function
main(sys.argv)
