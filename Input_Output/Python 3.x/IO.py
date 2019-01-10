# input() is used to take input in string format frm stdin.
input_string = input()

# you can cast it int, float, etc as you want
input_float = float(input())

import math
# This prints 3 inegers seperated by a sible space
print(round(input_float), math.floor(input_float), math.ceil(input_float))

# Input as list a series of number of unknown length seperated by ' ' on a single line
# Sample Input
# 1 2 3 4 5
M = list(map(int, input().split(' ')))

# Print length of list
print(len(M))

increment = int(input())

# Inceremt each digit by increment value
M = list(map( lambda a: a+increment, M))

# Either numberator or denominator need to be a float for float division
print(max(M)/2.0)

# Print message and incremented array in a single line seperated by ' '
print("All elements incremented by " + str(increment) + ": " + ' '.join(map(str, M)))
