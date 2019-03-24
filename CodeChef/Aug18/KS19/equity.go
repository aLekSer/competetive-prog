package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
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
	n, _ = strconv.Atoi(s.strs[s.pos])
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

/////////////////////

func main() {
	t := GetInt()

	for i := 0; i < t; i++ {
		n := GetInt()
		p := int64(GetInt())
		v := make([]int, 0)
		size := int64(10000)
		a := make([]int64, size+1)
		for j := 0; j < n; j++ {
			s := GetInt()
			v = append(v, s)
			a[s]++
		}
		minT := int64(math.MaxInt64)
		for k := int64(1); k <= size; k++ {
			tot := int64(0)
			f := int64(0)
			if a[k] > 0 {
				for j := k; j > 0; j-- {
					tot += a[j]
					if tot >= p {
						f += (a[j] - (tot - p)) * (k - j)
						if f < minT {
							minT = f
						}
						break
					}
					f += (a[j]) * (k - j)
				}
			}
		}
		fmt.Print("Case #", (i + 1), ": ")
		fmt.Println(minT)

	}
}
