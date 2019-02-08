package main

import (
    "fmt"
    "container/list"
)

func main() {
    l := list.New()
    l.PushFront(67)
    l.PushBack("first")

    for i:=l.Front(); i!=nil; i=i.Next() {
        fmt.Println(i.Value)
    }
}