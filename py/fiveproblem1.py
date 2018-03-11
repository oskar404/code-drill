#!/usr/bin/env python
# Write three functions that compute the sum of the numbers in a given list
# using a for-loop, a while-loop, and recursion.

def forloop(arr):
    result = 0
    for i in arr:
        result += i
    return result

def whileloop(arr):
    # This is cumbersome way to iterate in Python
    result = 0
    i = 0
    while i < len(arr):
        result += arr[i]
        i += 1
    return result

def recursion(idx, arr):
    if idx >= len(arr):
        return 0
    return arr[idx] + recursion(idx+1, arr)


arr1=[1,2,3,4,5,6,7,8,9]
arr2=[10,-2,13,-4,-5,66,17,-98,-9]

print("sum({}) = {}".format(arr1, forloop(arr1)))
print("sum({}) = {}".format(arr1, whileloop(arr1)))
print("sum({}) = {}".format(arr1, recursion(0, arr1)))

print("sum({}) = {}".format(arr2, forloop(arr2)))
print("sum({}) = {}".format(arr2, whileloop(arr2)))
print("sum({}) = {}".format(arr2, recursion(0, arr2)))

