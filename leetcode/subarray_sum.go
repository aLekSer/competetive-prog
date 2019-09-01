// 556 Subarray sum equals K
/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2

Ex 2: 
[0 0 0 0 0 0 0 0 0 0]
0
Output : 55

*/

func subarraySum(nums []int, k int) int {
    t := map[int] int {}
    
    sums := 0 
    s := 0
    t[0] = 1
    for _,v := range nums {
       sums += v
        // m[i+1] - m[i] == k
        // m[i+1] -k = m[i]
        if _, ok := t[sums- k]; ok {
            s +=  t[sums - k]
        }
        t[sums] += 1
    }
    return s
}
