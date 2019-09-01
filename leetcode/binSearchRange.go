package main

/// 34. Find First and Last Position of Element in Sorted Array
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].

Used binary search a bit updated, twice apply binary search for left and right border
*/

var lll = -1
var rrr = -1

func bin(nums []int, l, r, t, ll, rr int) []int {
	if len(nums) == 0 {
		return []int{-1, -1}
	}
	if l > r {
		return []int{ll, rr}
	}
	m := (l + r) / 2
	if nums[m] > t {
		bin(nums, l, m-1, t, ll, rr)
	} else if nums[m] < t {
		bin(nums, m+1, r, t, ll, rr)
	} else {
		if ll == -1 {
			if m == 0 || nums[m-1] < t {
				//fmt.Println("here", m)
				lll = m
				bin(nums, m+1, r, t, m, rr)
			} else {
				bin(nums, l, m-1, t, -1, rr)
			}
		}
		if rr == -1 {
			if m == len(nums)-1 || nums[m+1] > t {
				bin(nums, m+1, r, t, ll, m)
				//fmt.Println("here", m)
				rrr = m
			} else {
				bin(nums, m+1, r, t, ll, -1)
			}
		}
	}
	return []int{lll, rrr}
}
func searchRange(nums []int, target int) []int {
	lll = -1
	rrr = -1
	return bin(nums, 0, len(nums)-1, target, -1, -1)
}
