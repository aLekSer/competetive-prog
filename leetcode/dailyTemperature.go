// 739. Daily Temperatures
/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Using stack with indices while going from the end of the list
*/

func dailyTemperatures(T []int) []int {
	ans := make([]int, len(T))
	stack := []int{}

	for i := len(T) - 1; i >= 0; i-- {
		for len(stack) > 0 && T[i] >= T[stack[len(stack)-1]] {
			stack = stack[:len(stack)-1]
		}
		if len(stack) > 0 {
			ans[i] = stack[len(stack)-1] - i
		}
		stack = append(stack, i)
	}
	return ans
}