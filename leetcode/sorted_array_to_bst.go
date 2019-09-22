// 108. Convert Sorted Array to Binary Search Tree
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func NewT(v int) *TreeNode {
    return &TreeNode{Val: v, Left: nil, Right:nil}
}

func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums ) == 0 {
        return nil
    }
    c := len(nums)/2
    root := NewT(nums[c])
    
    left := nums[:c]
    right := nums[c+1:]
    root.Left = sortedArrayToBST(left)
    root.Right = sortedArrayToBST(right)
    return root
}
