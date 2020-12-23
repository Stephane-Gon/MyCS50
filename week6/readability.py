from cs50 import get_string


def main():

    text = get_string("Text: \n")

    numberLetters = countLetters(text)
    numberWords = countWords(text)
    numberSentences= countSentences(text)
    grade = calculateGrade(numberWords, numberLetters, numberSentences)

    if grade < 1:
        print("Before grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def countLetters(text):
    counterL = 0

    for i in range(len(text)):
        if text[i].isalpha():
            counterL += 1
    return counterL


def countWords(text):
    counterW = 0

    for i in range(len(text)):
        if text[i] == ' ':
            counterW += 1

    return counterW + 1


def countSentences(text):
    counterS = 0

    for i in range(len(text)):
        if text[i] in ['.', '?', '!']:
            counterS += 1

    return counterS


def calculateGrade(word, letter, sentence):

    result = 0.0588 * (100 * float(letter) /  float(word)) - 0.296 * (100 * float(sentence) / float(word)) - 15.8;

    return round(result)


main()