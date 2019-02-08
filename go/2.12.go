package main

import (
    "fmt"
)

func swap(a, b *int) {
    t := *a
    *a = *b
    *b = t
}

func main() {
    str := "This is string..."

    ptr := &str

    fmt.Printf("ptr type: %T\n", ptr)
    fmt.Printf("ptr address: %p\n", ptr)

    value := *ptr

    fmt.Printf("value type: %T\n", value)
    fmt.Printf("value value: %s\n", value)

    fmt.Println("\nswap:")

    a := 1
    b := 2
    fmt.Printf("origin value: a=%d, b=%d\n", a, b)
    swap(&a, &b)
    fmt.Printf("swap value: a=%d, b=%d\n", a, b)
}
