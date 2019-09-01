import "sort"

//347. Top K Frequent Elements

func topKFrequent(nums []int, k int) []int {
	m := map[int]int{}
	for _, v := range nums {
		m[v] += 1
	}
	s := [][2]int{}
	for k, v := range m {
		s = append(s, [2]int{k, v})
	}
	sort.Slice(s, func(i, j int) bool { return s[i][1] > s[j][1] })
	a := []int{}
	for i := 0; i < k; i++ {
		a = append(a, s[i][0])
	}
	return a
}