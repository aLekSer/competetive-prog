// Useful wiki https://github.com/golang/go/wiki/SliceTricks

package program
/**/
import (
"fmt"
)

func perm(ar []int, cur []int, res* [][]int) [][]int{
	if len(ar) == 0 && len(cur) != 0 {
		fmt.Println("here", cur)
		*res = append(*res, cur)
	}
	for i, v := range ar {
		m := make([]int, len(ar))
		copy(m, ar)
		m = append(m[:i] , m[i+1:]... )
		cur2 := append(cur, v)
		perm(m, cur2, res)
	}
	return *res
}
func GetPermutations(array []int) [][]int {
	v := []int{}
	r := [][]int{}
	fmt.Println(r)
	r2 := perm(array, v, &r )
	fmt.Println(r2, len(r2))
	return r2
}
