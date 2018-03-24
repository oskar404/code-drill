// Write a function that combines two lists by alternatingly taking elements.
// For example: given the two lists [a, b, c] and [1, 2, 3], the function should
// return [a, 1, b, 2, c, 3].
package main

import "fmt"

func alternate(l1 []string, l2 []string) (result []string) {
    size := len(l1)
    if len(l2) > size {
        size = len(l2)
    }
    for i := 0; i < size; i++ {
        if i < len(l1) {
            result = append(result, l1[i])
        }
        if i < len(l2) {
            result = append(result, l2[i])
        }
    }
    return
}

func main() {
    v1 := []string{"A", "B", "C", "D"}
    v2 := []string {"1", "2", "3", "4", "XX", "YY"}
    fmt.Println(alternate(v1, v2))
    fmt.Println(alternate(v2, v1))
}
