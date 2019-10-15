// 76. Minimum Window Substring

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"

Also met this task on pramp.com 
*/

minWindow(s string, t string) string {
    ta := map[byte] int {}
    c := 0
    for _, i := range t {
        ta[byte(i)] ++
        c ++
    }
    let := map[byte] int{}
    st := 0
    f := 0
    i := 0
   res := ""
    mi := 1000000
    fChanged := true
    for {
        if f == len(s)  {
            break
        }
        if ta[s[f]] != 0 && fChanged == true {
            if  let[s[f] ] < ta[s[f]] {
              i ++
            }
            fChanged = false
            let[s[f]] ++
        }
        if i == c && f - st < mi{
            mi = f - st
            res = s[st:f+1]
        }
       // fmt.Println(st, " ", f, " i ", i, "  ", c)
        if i < c  || st == f{
            f ++
            fChanged = true
        } else {
            if ta[s[st]] != 0 {
                let[s[st]] --
              //  fmt.Println(let, ta)
                if  let[s[st] ] < ta[s[st]] {
                  //  fmt.Println(string(s[st]))
                  i --
                }
            }
            st ++
        }
    }
    /*
    for {
         if ta[s[st]] != 0 {
                let[s[st]] --
                i --
             fmt.Println("Dec")
            }
            st ++
        if st == f {
            break
        }
        if i == c && f - st < mi{
            mi = f - st
            res = s[st:f+1]
        }
        fmt.Println(st, " 2 ", f)
    }
    */
    return res
}
