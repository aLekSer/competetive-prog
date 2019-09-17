// 384. Shuffle an Array
// Fisher-Yates Algorithm


import (
    r "math/rand"
)

type Solution struct {
    Nums []int
    Original []int
}


func Constructor(nums []int) Solution {
    Original := make([]int, len(nums))
    Nums := make([]int, len(nums))
    copy(Nums, nums)
    copy (Original, nums)
    return Solution{Nums:  Nums, Original: Original}
}


/** Resets the array to its original configuration and return it. */
func (this *Solution) Reset() []int {
    copy(this.Nums, this.Original)
    return this.Original
}


/** Returns a random shuffling of the array. */
func (this *Solution) Shuffle() []int {
    i := len(this.Nums) - 1
	for ; i > 0; i-- {
		j := int(r.Int31n(int32(i + 1)))
        this.Nums[i], this.Nums[j] = this.Nums[j], this.Nums[i]
	}
    return this.Nums
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Reset();
 * param_2 := obj.Shuffle();
 */
