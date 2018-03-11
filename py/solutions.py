#!/usr/bin/python3
# Write a program that outputs all possibilities to put + or - or nothing
# between the numbers 1, 2, ..., 9 (in this order) such that the result is
# always 100. For example: 1 + 2 + 34 - 5 + 67 - 8 + 9 = 100.

NUMBERS = [1,2,3,4,5,6,7,8,9]
SUM = 100
BUFFER = [1]

def to_equation(buf):
    result = ''
    for i in buf:
        if len(result) == 0:
            result = str(i)
        else:
            if i > 0:
                result = result + ' + ' + str(i)
            else:
                result = result + ' - ' + str(abs(i))
    return result

def resolve(idx):

    global BUFFER

    # Check if we have recursed to depth
    if idx >= len(NUMBERS):
        if sum(BUFFER) == SUM:
            print("{} = {}".format(to_equation(BUFFER), SUM))
        return;

    # Branch 1: Add number to previous
    BUFFER.append(NUMBERS[idx])
    resolve(idx+1)
    BUFFER = BUFFER[:-1]

    # Branch 2: Subtract number from previous
    BUFFER.append(-1*NUMBERS[idx]);
    resolve(idx+1);
    BUFFER = BUFFER[:-1]

    # Branch 3: Concatenate number to previous
    prev = BUFFER[-1]
    BUFFER[-1] = (10 * abs(prev) + NUMBERS[idx]) * (1 if prev >= 0  else -1)
    resolve(idx+1)
    BUFFER[-1] = prev


resolve(1)

