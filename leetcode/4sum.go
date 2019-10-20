package program

import "fmt"

func FourNumberSum(array []int, target int) [][]int {
	// Write your code here.
	r := [][]int{}
	m := map[int][][2]int{}
	for i, _ := range array {
		for j := i + 1; j < len(array); j++ {
			if el, ok := m[target-array[i]-array[j]]; ok {
				for _, d := range el {
					v := []int{}
					v = append(v, array[i])
					v = append(v, array[j])

					v = append(v, d[0])
					v = append(v, d[1])
					r = append(r, v)
				}
			}
		}
		for j := 0; j < i; j++ {
			v := [2]int{array[i], array[j]}
			m[array[i]+array[j]] = append(m[array[i]+array[j]], v)
		}
	}
	fmt.Println(r)
	return r
}
