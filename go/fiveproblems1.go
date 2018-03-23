// Write three functions that compute the sum of the numbers in a given list
// using a for-loop, a while-loop, and recursion.
package main

import "fmt"

func forloop(list []int) (sum int) {
    for _, item := range list {
        sum += item
    }
    return
}

// There is no while loop in Go. The for loop works also as while
func whileloop(list []int) (sum int) {
    i := 0
    for i < len(list) {
        sum += list[i]
        i++
    }
    return
}

func recursion(list []int, size int) int {
    if size == 0 {
        return 0
    }
    size--
    return list[size] + recursion(list, size)
}

func main() {
    primes := []int{1, 2, 3, 5, 7, 11}
    fibonacci := []int{0, 1, 1, 2, 3, 5, 8, 13}
    fmt.Printf("forloop: %d\n", forloop(fibonacci))
    fmt.Printf("whileloop: %d\n", whileloop(primes))
    fmt.Println("recursion:", recursion(fibonacci, len(fibonacci)))
}
