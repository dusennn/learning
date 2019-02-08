package main

import (
    "fmt"
)

func main() {
    var arr = [5] int {12, 3, 34, 5, 6}

    for k, v := range arr {
        fmt.Println("Index:", k, ", Value:", v)
    }

    fmt.Println(arr, arr[1:2])

    arr2 := make([]int, 2)
    arr3 := make([]int, 2, 10)

    fmt.Println(arr2)
    fmt.Println(arr3)
}
