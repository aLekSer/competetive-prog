package main

import "fmt"

func main2() {
	n := 0
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var a [4]int
		var m map[int]int = make(map[int]int)
		for j := 0; j < 4; j++ {
			fmt.Scan(&a[j])
			if _, ok := m[a[j]]; ok {
				m[a[j]]++
			} else {
				m[a[j]] = 1
			}
		}
		fmt.Println(a[0])

		all := true
		for _, v := range m {
			all = all && ((v == 2) || (v == 4))
		}
		if all {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
	return
}
