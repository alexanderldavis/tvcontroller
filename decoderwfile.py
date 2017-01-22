# Alexander Davis
# The following takes raw data from an Arduino IR receiver to prep it for the transmitter code.

file = open("file.txt", "r")
newfile = open("newfile.txt", "w")
number1 = []
number2 = []
for line in file:
    myline = line.split(" usec, ")

    for word in myline:
        if " usec\n" not in word and "\n" not in word:
            print(word)
            number1.append(word)
        else:
            print(word[:-6])
            number2.append(word[:-6])
print(number1)
print(number2)

for number in range(len(number1)):
    newfile.write("\tdelayMicroseconds("+number1[number]+");\n\tpulseIR("+number2[number]+");\n")
