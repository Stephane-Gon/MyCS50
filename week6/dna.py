from sys import argv
import csv

def main(argv):

    # Here I check if the user typed the right number of arguments
    if len(argv) != 3:
        print('Usage: python dna.py data.csv sequence.txt')

    # Here I open the text file, read it and change is content to strings
    textFile = open(argv[2], 'r')
    lines = textFile.readlines()
    strLines = str(lines)

    # Here I open the csv File, and read it into an empty list row by row
    csvFile = open(argv[1], 'r')
    reader = csv.reader(csvFile)
    listFromCsv = []
    for row in reader:
        listFromCsv.append(row)

    #Here I create a list with the STR only, wich i get from the first row of the CSV file
    line1 = listFromCsv[0]

    #Here I call the secondary functions
    result = countSequence(line1, strLines)
    checkMatch = check(result, listFromCsv)

    # Here I close the Files
    textFile.close()
    csvFile.close()

    # Here I print the result
    print(checkMatch)

# Function that counts STR's in a row in a sequence of STR's
def countSequence(strToCheck, strSequence):

    # Variable to keep the different results for each iteration in the 2D Loop
    final_result = []

    # Here I make a 2D Loop, so I can loop trough the STR we have to check and the sequence
    for item in strToCheck:

        # Here I create 3 variables;
        # One keeps incrementing every time the STR is found in the sequence;
        # The other keeps track of the longest sequence in a row
        # And the other keeps track if the STR I'm checking will repeat in sequence
        counter = 0
        maxValue = 0
        willRepeat = False

        for i in range(len(strSequence)):
            # Var that keeps track of a sequence of characther the size of the STR we are checking
            subString = strSequence[i : i + len(item)]

            # Here I have a set of conditions that check if the current STR matches the "subString" element in the sequence, and if we have another one coming.
            # And updates the "maxValue" variable when needed
            if subString == item:
                counter += 1
            elif willRepeat == True:
                continue
            if strSequence[i + len(item) : i + (len(item) * 2)] == item:
                willRepeat = True
            else:
                willRepeat = False
                if maxValue <= counter:
                   maxValue = counter
                   counter = 0
                else:
                    counter = 0

        # Here I append the result for each STR I have to check to the final_result
        final_result.append(str(maxValue))

    return final_result


def check(result, listFromCsv):

    # This variable keeps track of how many results from the "countSequence" function, match someone from the CSV file
    counter = 0

    # 2D LOOP to iterate trough the list's inside "listFromCSV"
    for i in range(len(listFromCsv)):

        for j in range(len(listFromCsv[i])):

            # Here I Have a set of conditions that check if the results we got from the "countSequence" function match any of the people in the CSV file
            # By incrementing the counter by 1 if one of the results match or breaking the loop if 1 of the results does not match
            if result[j] == listFromCsv[i][j]:
                counter += 1
            elif j == 0:
                counter += 1
            else:
                counter = 0
                break
        # If the counter is the same as the length of one of the list's it means we found a match so I update the "final_result" var and brak the loop
        # If not it means the is no Match
        if counter == len(listFromCsv[i]):
            final_result = listFromCsv[i][0]
            break
        else:
            final_result = 'No Match'

    return final_result

main(argv)