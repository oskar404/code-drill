// Write a function that given a list of non negative integers, arranges them
// such that they form the largest possible number. For example, given
// [50, 2, 1, 9], the largest formed number is 95021.
package main

import (
    "bytes"
    "fmt"
    "strconv"
    "sort"
    "os"
)

type intSorter []int

func (s intSorter) Len() int {
    return len(s)
}

func (s intSorter) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s intSorter) Less(i, j int) bool {
    lhs := strconv.Itoa(s[i])
    rhs := strconv.Itoa(s[j])
    var lhsbuf bytes.Buffer
    var rhsbuf bytes.Buffer
    lhsbuf.WriteString(lhs)
    lhsbuf.WriteString(rhs)
    rhsbuf.WriteString(rhs)
    rhsbuf.WriteString(lhs)
    return lhsbuf.String() > rhsbuf.String()
}

func main() {
    input := make([]int, 0, 5) 
    for _, arg := range os.Args[1:] {
        value, err := strconv.Atoi(arg)
        if err != nil {
            fmt.Fprintln(os.Stderr, "Error: Not a number:", arg)
            os.Exit(1)
        }
        if value < 0 {
            fmt.Fprintln(os.Stderr, "Error: negative integer:", value)
            os.Exit(1)
        }
        input = append(input, value)
    }
    fmt.Print(input)
    fmt.Print(" -> ")
    sort.Sort(intSorter(input))
    for _, value := range input {
        fmt.Print(value)
    }
    fmt.Print("\n")
}
