#!/bin/bash
# Write a function that combines two lists by alternatingly taking elements.
# For example: given the two lists [a, b, c] and [1, 2, 3], the function should
# return [a, 1, b, 2, c, 3].

V1=("A" "B" "C" "D")
V2=(1 2 3 4)
RESULT=()

function alternate()
{
    echo ${#V1[@]}
    echo ${#V2[@]}
    
    if [ ${#V1[@]} != ${#V2[@]} ]; then
        echo "Vectors do not have same size"    
    fi

    for i in $(seq 0 $((${#V1[@]} - 1)) ) ; do
        RESULT=("${RESULT[@]}" "${V1[$i]}" "${V2[$i]}")
    done
}

alternate
echo "${RESULT[@]}"
