package main

import (
    "fmt"
)

func main(){
    str := "Hello World !"
    ch := "中文"

    longstr := `
    1
    2
    3
    4
    `

    fmt.Println(str, "\n", ch, "\n", longstr)
}
