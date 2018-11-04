#!/bin/bash
# Write a function that computes the list of the first 100 Fibonacci numbers.
# By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
# and each subsequent number is the sum of the previous two. As an example,
# here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.

function fibonacci()
{
    local i1=0
    local i2=1
    local i=2
    [[ $1 == 0 ]] && return
    echo $i1
    [[ $1 == 1 ]] && return
    echo $i2
    [[ $1 == 2 ]] && return
    while [[ $i -lt $1 ]] ; do
        local i3=$((i1 + i2))
        [[ $i3 -lt $i2 ]] && (>&2 echo "Overflow at: $i") && return
        echo $i3
        i1=$i2
        i2=$i3
        i=$((i+1))
    done
}


USAGE="usage: fibonacci.sh <count>"
[[ $1 == "-h" ]] && (>&2 echo "$USAGE") && exit 1
COUNT=100
[[ -n $1 ]] && COUNT=$1
[[ -z ${COUNT##*[!0-9]*} ]] && (>&2 echo "Not a positive number: $1") && exit 1

fibonacci "$COUNT"
