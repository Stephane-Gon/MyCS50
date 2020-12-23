from cs50 import get_float

counter = 0

change = -1
while change < 0:
    change = get_float("Change owed: ")
    
cents = round(change * 100)

while cents >= 25:
    cents -= 25
    counter += 1

while cents >= 10:
    cents -= 10
    counter += 1

while cents >= 5:
    cents -= 5
    counter += 1

while cents >= 1:
    cents -= 1
    counter += 1

print(counter)
    
