package main

import (
    "fmt"
)

func main() {
    fmt.Println("https://zhidao.baidu.com/question/744094337901801772.html?qbl=relate_question_0&word=%C8%E7%BA%CE%B0%BE%B0%D7%B4%D7")
    
    for x:=1; x<=9; x++ {
        for y:=1; y<=x; y++ {
            fmt.Printf("%d*%d=%d ", x, y, x*y)
        }
        fmt.Println()
    }
}
