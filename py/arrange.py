#!/usr/bin/env python
# Write a function that given a list of non negative integers, arranges them
# such that they form the largest possible number. For example, given
# [50, 2, 1, 9], the largest formed number is 95021.

import sys

class Sorter:
    def __init__(self, inner):
        self.inner = inner

    def __lt__(self, other):
        lhs = str(self.inner) + str(other.inner)
        rhs = str(other.inner) + str(self.inner)
        return lhs > rhs

def arrange(numbers):
    numbers.sort(key = Sorter)
    result = ''
    for n in numbers:
        result += str(n)
    return result

def main():
    assert len(sys.argv) >= 2, "Missing arguments. Give list of numbers."
    numbers = list(map(int, sys.argv[1:]))
    assert sum(1 for n in numbers if n < 0) == 0, "Number arguments must be positive"
    print("{}".format(arrange(numbers)))


if __name__ == '__main__':
    main()
