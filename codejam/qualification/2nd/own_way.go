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
        for j := 0; j < len(n); j++ {
			c := n[j]
            if c == 'E' {
                a = append(a, 'S')
               
            } else {
                a = append(a, 'E')
            }
		}
    return string(a)
    
}

func main() {
	t := GetInt()
   // fmt.Println(t)
	for i := 0; i < t; i++ {
        GetInt()
        s := GetStr()
        //fmt.Println(s)
        res := cover(s)
        fmt.Printf("Case #%d: %s\n", (i + 1), string(res))
	}

}
