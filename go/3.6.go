package main

import (
    "fmt"
    "sync"
)

func syncMap(){
    // 创建一个int到int的映射
    m := make(map[int]int)
    // 开启一段并发代码
    go func() {
        // 不停地对map进行写入
        for {
            m[1] = 1
        }
    }()
    // 开启一段并发代码
    go func() {
        // 不停地对map进行读取
        for {
            _ = m[1]
        }
    }()
    // 无限循环, 让并发程序在后台执行
    for {
    }
}

func main() {
    dict := map[string]int{
        "a":96, 
        "b":97, 
        "c":98,
        }

    fmt.Println(dict)
    for k, v := range dict {
        fmt.Println(k, v)
    }

    dict2 := make(map[string]int)
    dict2["test"] = 10

    fmt.Println(dict2)

    // sync map
    syncMap()
}