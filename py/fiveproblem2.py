#!/usr/bin/env python
# Write a function that combines two lists by alternatingly taking elements.
# For example: given the two lists [a, b, c] and [1, 2, 3], the function should
# return [a, 1, b, 2, c, 3].

def alternate(arr1, arr2):
    return [x for t in list(zip(arr1, arr2)) for x in t]


arr1=[1,2,3,4]
arr2=["A", "B", "C", "D"]
arr3=["X", "Y"]

print("{}".format(alternate(arr1, arr2)))
print("{}".format(alternate(arr2, arr1)))
print("{}".format(alternate(arr3, arr2)))

