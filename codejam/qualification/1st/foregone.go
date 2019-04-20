package main


//

import (
	"fmt"
	"io/ioutil"
	"os"
	//"sort"
	"strconv"
	"strings"
	"unicode"
)

var stdin *Scanner

type Scanner struct {
	strs []string
	pos  int
}


func (s *Scanner) readAll(f *os.File) {
	bytes, _ := ioutil.ReadAll(f)

	s.strs = strings.Split(strings.Map(func(r rune) rune {
		if unicode.IsSpace(r) {
			return ' '
		}
		return r
	}, string(bytes)), " ")
}

func (s *Scanner) GetStr() string {
	str := s.strs[s.pos]
	s.pos++
	return str
}

func (s *Scanner) GetInt() (n int) {
	n, err := strconv.Atoi(s.strs[s.pos])
	if err != nil {
		panic(err)
	}
	s.pos++
	return
}

func init() {
	stdin = &Scanner{}
	stdin.readAll(os.Stdin)
}

func GetStr() (s string) {
	return stdin.GetStr()
}

func GetInt() (n int) {
	return stdin.GetInt()
}

//

func cover(s string) string {
        n := []byte(s)
        a := make([]byte, 0)
        b := make([]byte, 0)
       found := false
        for j := 0; j < len(n); j++ {
			c := n[j]
            if c == '4' {
                a = append(a, '3')
                b = append(b, '1')
               found = true
            } else {
                a = append(a, c)
                if found {
                   b = append(b, '0')
                }
            }
		}
    return fmt.Sprintf("%s %s", string(a), string(b))
    
}

func main() {
	t := GetInt()
   // fmt.Println(t)
	for i := 0; i < t; i++ {
        s := GetStr()
        //fmt.Println(s)
        res := cover(s)
        fmt.Printf("Case #%d: %s\n", (i + 1), string(res))
	}

}
