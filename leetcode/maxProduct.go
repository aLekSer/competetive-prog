/// 152. Maximum Product Subarray
func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func maxProduct(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	mi := nums[0]
	ma := nums[0]
	cu := nums[0]
	for i := 1; i < len(nums); i++ {
		x := nums[i] * mi
		y := nums[i] * ma
		mi = min(x, min(y, nums[i]))
		t := max(x, max(y, nums[i]))
		cu = max(cu, t)
		ma = t
	}
	return cu
}