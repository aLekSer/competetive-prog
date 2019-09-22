//890. Find and Replace Pattern
/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.
A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
Return a list of the words in words that match the given pattern. 
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Not in output: ["dkd", ...]
*/

func findAndReplacePattern(words []string, pattern string) []string {
    r := [26]int{}
    for _, v := range pattern {
        r[int(v-'a')] ++
    }
    sort.Ints(r[:])
    m := map[[26]int]bool{}
    m[r] = true
    res := []string{}
    for _, w := range words {
        
        r2 := [26]int{}
        for _, v := range w {
            r2[int(v-'a')] ++
        }
        sort.Ints(r2[:])
        if _, ok := m[r2]; ok {
            m := map[rune]rune{}
            b := true
            for i, v := range w {
                if e, ok := m[v] ; ok {
                    b = rune(pattern[i]) == e
                } else {
                    m[v] = rune(pattern[i])
                }
            }
            if b {
                res = append(res, w)
            }
        }
    }
    return res
}
