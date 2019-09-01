// 19. Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	fast := head
	slow := head
	for i := 0; i < n; i++ {
		fast = fast.Next
	}
	for fast != nil && fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}
	if fast == nil {
		head = head.Next
	} else {
		slow.Next = slow.Next.Next
	}
	return head
}