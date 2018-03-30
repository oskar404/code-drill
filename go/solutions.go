// Write a program that outputs all possibilities to put + or - or nothing
// between the numbers 1, 2, ..., 9 (in this order) such that the result is
// always 100. For example: 1 + 2 + 34 – 5 + 67 – 8 + 9 = 100.
package main

import (
    "fmt"
)

var NUMBERS [9]int = [9]int{1,2,3,4,5,6,7,8,9}
var SUM int = 100

func print(solution []int) {
    for i, v := range solution {
        switch {
        case i == 0:
            fmt.Printf("%d ", v)
        case v < 0:
            fmt.Printf("- %d ", -1 * v)
        default:
            fmt.Printf("+ %d ", v)
        }
    }
    fmt.Printf(" = %d\n", SUM)
}

func concatenate(lhs, rhs int) (result int) {
    sign := 1
    val := lhs
    if lhs < 0 {
        sign = -1
        val = -1 * lhs
    }
    result = sign * (10 * val + rhs)
    return
}

func recurse(buf []int, idx int) {
    // Check if we have recursed to depth
    if idx >= len(NUMBERS) {
        result := 0
        for _, v := range buf {
            result += v
        }
        if result == SUM {
            print(buf)
        }
        return
    }

    // Branch 1: Add number to previous
    buf = append(buf, NUMBERS[idx])
    recurse(buf, idx+1)
    buf = buf[:len(buf)-1]

    // Branch 2: Subtract number from previous
    buf = append(buf, -1 * NUMBERS[idx])
    recurse(buf, idx+1)
    buf = buf[:len(buf)-1]

    // Branch 3: Concatenate number to previous
    prev := buf[len(buf)-1]
    buf[len(buf)-1] = concatenate(prev, NUMBERS[idx])
    recurse(buf, idx+1);
    buf[len(buf)-1] = prev;
}

func main() {
    buf := make([]int, 0, 9)
    buf = append(buf, NUMBERS[0])
    recurse(buf, 1)
}
