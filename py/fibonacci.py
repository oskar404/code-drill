#!/usr/bin/env python
# Write a function that computes the list of the first 100 Fibonacci numbers.
# By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
# and each subsequent number is the sum of the previous two. As an example,
# here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.

import sys

def fibonacci(size):
    buf = [0, 1]
    if size <= 2:
        return buf[:size]
    size -= 2
    while size >= 0:
        buf.append(buf[-1]+buf[-2])
        size -= 1
    return buf

def main():
    assert len(sys.argv) == 2, "Missing number argument or too many arguments"
    size = int(sys.argv[1])
    assert size >= 0, "Number argument must be positive"
    print("{}".format(fibonacci(size)))


if __name__ == '__main__':
    main()
