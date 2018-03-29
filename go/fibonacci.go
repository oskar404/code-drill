// Write a function that computes the list of the first 100 Fibonacci numbers.
// By definition, the first two numbers in the Fibonacci sequence are 0 and 1,
// and each subsequent number is the sum of the previous two. As an example,
// here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.
package main

import (
    "fmt"
    "strconv"
    "os"
)

type IntegerOverflow struct {
	Where int
}

func (e *IntegerOverflow) Error() string {
	return fmt.Sprintf("Integer overflow at %d", e.Where)
}

func fibonacci(size int) (result []int, err error) {
    for i := 0; i < size; i++ {
        switch {
        case i == 0:
            result = append(result, 0)
        case i == 1:
            result = append(result, 1)
        default:
            next := result[i-1]+result[i-2]
            if next < result[i-1] {
                err := &IntegerOverflow{i}
                return result, err
            }
            result = append(result, next)
        }
    }
    return
}

func main() {
    size := 100
    if len(os.Args) >= 2 {
        input, err := strconv.Atoi(os.Args[1])
        if err != nil {
            fmt.Fprintln(os.Stderr, "Invalid input:", os.Args[1])
            os.Exit(1)
        }
        size = input
    }
    sequence, err := fibonacci(size)
    fmt.Println(sequence)
    if err != nil {
        fmt.Println(err.Error())
    }
}
