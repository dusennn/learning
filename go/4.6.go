package main

import (
    "fmt"
)

func main(){

    for i:=0; i<5; i++{
        for j:=0; j<5; j++{
            if k:=i*j; k%2==0{
                goto breakHear
            }
        }
    }

    breakHear:
        fmt.Println("Done!")
}