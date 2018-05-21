package main

import "fmt"
import "bufio"
import "strconv"
import "os"
/*
MAXSC - problem name
import "container/heap"

type MaxHeap struct {
    IntHeap
}
func (h MaxHeap) Less(i, j int) bool { return h.IntHeap[i] > h.IntHeap[j] }*/
func maxUnder(a [700]int32, prevMax int32, N int) int32{
	var max int32
	max = -5
	for k := 0; k < N; k++ {
		if (a[k] > max) && (a[k] < prevMax) {
			max = a[k]
		}
	}
	return max
}
func toInt(buf []byte) (n int32) {
    for _, v := range buf {
        n = n*10 + int32(v-'0')
    }
    return
}
func main() {
	T := 0
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	b2, _ := strconv.Atoi(scanner.Text())
	T = b2
	var a [700][700]int32
	for i := 0; i < T; i++ {
		N := 0
		scanner.Scan()
		b2, _ := strconv.Atoi(scanner.Text())
		N = b2
		//fmt.Println(N)
		//fmt.Scan(&N)
		for k := 0; k < N; k++ {
			for l := 0; l < N; l++ {
				var b int32
				scanner.Scan()
				b2, _ := strconv.Atoi(scanner.Text())
				b = int32(b2)
				//fmt.Println(b)
				//fmt.Scan(&b)
				a[k][l] = b
			}
		}
		var sum int64
		sum = 0
		var max2 int32
		max2 = 2000000000
		var stop bool
		stop = false
		for k := N-1; k >=0; k-- {
			max2 = maxUnder(a[k], max2, N)
			sum += int64(max2)
			if max2 == -5 {
				stop = true
				break
			}
		}
		if stop {
			fmt.Println(-1)

		} else {
			fmt.Println(sum)
		}
		/*
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
		}*/
	}
	return
}
