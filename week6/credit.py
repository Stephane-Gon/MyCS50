from cs50 import get_int
import sys

while True:
    cNumber = get_int("Number: ")
    if cNumber > 0:
        break

size = len(str(cNumber))

numbers = list()
divisor = 1

for i in range(size):
    numbers.append((cNumber // divisor) % 10)
    divisor *= 10
  
sum = 0

for i in range(1, size, 2):
    if numbers[i] * 2 < 10:
          sum += numbers[i] * 2
    else:
        sum = sum + (numbers[i] * 2) % 10 + ((numbers[i] * 2) //10) % 10
        
for i in range(0, size, 2):
    sum += numbers[i]
    
if (sum % 10) != 0:
    print("INVALID")
    
else:
    if size == 15 and numbers[size - 1] == 3 and (numbers[size - 2] == 4 or numbers[size - 2] == 7):
        print("AMEX")
    elif size == 16 and numbers[size - 1] == 5 and (numbers[size - 2] == 1 or numbers[size - 2] == 2
    or numbers[size - 2] == 3 or numbers[size - 2] == 4 or numbers[size - 2] == 5):
        print("MASTERCARD")
    elif (size == 13 or size == 16)  and numbers[size - 1] == 4:
        print("VISA")
    else:
        print("INVALID")

  
