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

func abs2(n int) int {
	return int(math.Abs(float64(n)))
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
func abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
func cover(r int, c int, vx []int, vy []int) int {

	t := make([][]int, r)
	for l := range t {
		t[l] = make([]int, c)
	}
	for j := 0; j < r; j++ {
		for k := 0; k < c; k++ {
			t[j][k] = math.MaxInt16
		}
	}
	for i := 0; i < len(vx); i++ {
		t[vx[i]][vy[i]] = 0
		for j := 0; j < r; j++ {
			for k := 0; k < c; k++ {
				dist := abs(vx[i]-int(j)) + abs(vy[i]-int(k))
				if dist < t[j][k] {
					t[j][k] = dist
				}
			}
		}
	}
	m := 0
	for j := 0; j < r; j++ {
		for k := 0; k < c; k++ {
			if m < int(t[j][k]) {
				m = int(t[j][k])
			}
		}
	}

	v := make([][]int, r)
	for l := range v {
		v[l] = make([]int, c)
	}
	be := math.MaxInt16
	for ii := 0; ii < r; ii++ {
		for jj := 0; jj < r; jj++ {
			for j := 0; j < r; j++ {
				for k := 0; k < c; k++ {
					v[j][k] = t[j][k]
				}
			}
			v[ii][jj] = 0
			for j := 0; j < r; j++ {
				for k := 0; k < c; k++ {
					dist := abs(ii-int(j)) + abs(jj-int(k))
					if dist < v[j][k] {
						v[j][k] = dist
					}
				}
			}
			m = 0
			for j := 0; j < r; j++ {
				for k := 0; k < c; k++ {
					if m < int(v[j][k]) {
						m = int(v[j][k])
					}
				}
			}
			if m < be {
				be = m
			}
		}
	}
	/*
		fmt.Println("st")
		for i := 0; i < len(vx); i++ {
			fmt.Println(vx[i], vy[i])
		}
		fmt.Println("vx")
	*/
	for i := 0; i < len(vx); i++ {
	}
	/*
		for j := 0; j < r; j++ {
			for k := 0; k < c; k++ {
				fmt.Print(v[j][k])
			}
			fmt.Println()
		}
	*/
	return be
}

func main() {
	t := GetInt()

	for i := 0; i < t; i++ {
		r := GetInt()
		c := GetInt()
		vx := make([]int, 0)
		vy := make([]int, 0)
		a := make([][]int, r)
		for l := range a {
			a[l] = make([]int, c)
		}
		b := make([][]int, r)
		for l := range b {
			b[l] = make([]int, c)
		}
		for j := 0; j < r; j++ {
			s := GetStr()
			for k := 0; k < len(s); k++ {
				if s[k] == '1' {
					//a[j][k] = 1
					vx = append(vx, int(j))
					vy = append(vy, int(k))
				}
			}
		}
		minT := cover(r, c, vx, vy)
		fmt.Print("Case #", (i + 1), ": ")
		fmt.Println(minT)

	}
}
