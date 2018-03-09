#!/bin/bash
# Write three functions that compute the sum of the numbers in a given list
# using a for-loop, a while-loop, and recursion.

function forloop()
{
    local val=0
    for i in $@ ; do
        val=$(($val + $i));
    done
    echo "forloop: $val"
}

function whileloop()
{
    local val=0
    local args=($@)
    local args_size=${#args[@]}
    local idx=0
    while [ $idx -lt $args_size ]; do
        val=$(($val + ${args[$idx]}));
        idx=$(($idx + 1)) 
    done
    echo "whileloop: $val"
}

function recursion()
{
    if [ $# == 0 ]; then
        return 0
    fi
    local val=$1
    shift
    recursion $@
    local result=$?
    return $(($val + $result))
}


VECTOR=(1 2 3 4 5 -4 -1)
forloop ${VECTOR[@]}
whileloop ${VECTOR[@]}
recursion ${VECTOR[@]}
recursion_result=$?
echo "recursion: ${recursion_result}"
