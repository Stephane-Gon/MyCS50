from cs50 import SQL
import sys
import csv

db = SQL("sqlite:///students.db")

def main(argv):

    # Check if the user typed the correct number of arguments
    if len(argv) != 2:
        sys.exit("Usage: python import.py characters.csv")

    # Open csv file the user prompted
    with open(argv[1], "r") as csvFile:
        reader = csv.DictReader(csvFile)

        #Iterate trough the dictionary created above row by row
        for row in reader:

            # Here I split the words in the name column from the csv into different strings
            nameSplited = row['name'].split()

            # Here I create a variable from the first index, that will be the firstName
            firstName = nameSplited[0]

            #Here I create 2 variables one for the house another for the birth
            house = row['house']
            birth = row['birth']

            #  Here I check if the var I got from spliting the name in the csv has 3 strings,
            # if true I assign a var with the middleName and another with the lastName
            # and then I insert the first/middle/last name, house and birth from this row to an row in the students.db
            if len(nameSplited) == 3:
                middleName = nameSplited[1]
                lastName = nameSplited[2]
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", firstName, middleName, lastName, house, birth)

            #  If last condition its False it means the var I got from spliting the csv Name only has 2 strings,
            # then I assign the middleName var the value "None" and the lastName var gets the index 1 string
            # and then I insert the first/middle/last name, house and birth from this row to an row in the students.db
            else:
                middleName = None
                lastName = nameSplited[1]
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", firstName, middleName, lastName, house, birth)


# Calling the function
main(sys.argv)

