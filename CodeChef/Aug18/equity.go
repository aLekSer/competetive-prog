package main

// https://codingcompetitions.withgoogle.com/hashcode/

/////////////////////

import (
	"fmt"
	"io/ioutil"
	"os"
	"sort"
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

/////////////////////

type photo struct {
	ID           string
	IsHorizontal bool
	Tags         map[string]bool
}

func combine(p1, p2 photo) photo {
	if p1.IsHorizontal || p2.IsHorizontal {
		panic("Unable to combine horizontal photos")
	}

	res := photo{p1.ID + " " + p2.ID, true, make(map[string]bool)}
	for t, _ := range p1.Tags {
		res.Tags[t] = true
	}
	for t, _ := range p2.Tags {
		res.Tags[t] = true
	}
	return res
}

func compare(p1, p2 photo) int {
	//	if !p1.IsHorizontal || !p2.IsHorizontal {
	//		panic("Unable to compare vertical photos")
	//	}

	common := 0
	for t, _ := range p2.Tags {
		if p1.Tags[t] {
			common++
		}
	}

	res := common
	if r := len(p1.Tags) - common; res > r {
		res = r
	}
	if r := len(p2.Tags) - common; res > r {
		res = r
	}
	return res
}

func calcMetric(photos []photo) (res int) {
	for i := 0; i < len(photos)-1; i++ {
		res += compare(photos[i], photos[i+1])
	}
	return
}

func printResult(photos []photo) {
	fmt.Println(len(photos))
	for i := 0; i < len(photos); i++ {
		fmt.Println(photos[i].ID)
	}
	return
}

func main() {
	n := GetInt()
	photos := make([]photo, 0, n)
	vPhotos := make([]photo, 0, n)
	for i := 0; i < n; i++ {
		p := photo{
			strconv.Itoa(i),
			GetStr() == "H",
			make(map[string]bool),
		}

		tagCount := GetInt()
		for j := 0; j < tagCount; j++ {
			tag := GetStr()
			p.Tags[tag] = true
		}
		if p.IsHorizontal {
			photos = append(photos, p)
		} else {
			vPhotos = append(vPhotos, p)
		}
	}

	// preliminary sort array of vertical photos by the number of tags
	//sort.Slice(vPhotos, func(i, j int) bool { return len(vPhotos[i].Tags) > len(vPhotos[j].Tags) })

	// combine vertical photos and add them to horizontal
	for i := 0; i < len(vPhotos)/2; i++ {
		photos = append(photos, combine(vPhotos[i*2], vPhotos[i*2+1]))
	}

	// preliminary sort array of photos by the number of tags
	sort.Slice(photos, func(i, j int) bool { return len(photos[i].Tags) > len(photos[j].Tags) })
	T := 200
	// sort photos maximizing the metric
	for i := 0; i < len(photos)-1; i++ {
		max := 0
		if i+1 < len(photos) {
			max = compare(photos[i], photos[i+1])
		}
		maxI := i + 1

		// test 100 photos
		for j := i + 1; j < i+T && j < len(photos); j++ {
			m := compare(photos[i], photos[j])
			if m > max {
				maxI = j
				max = m
			}
		}

		photos[i+1], photos[maxI] = photos[maxI], photos[i+1]
		// test 100 random photom
		/*
			if len(photos)-i > 100 {
				for j := 0; j < 10; j++ {
					d := rand.Intn(len(photos) - i - 100)
					m := compare(photos[i], photos[i+d])
					if m > max {
						maxI = j
						max = m
					}
				}
				photos[i+1], photos[maxI] = photos[maxI], photos[i+1]
			}
		*/
	}

	printResult(photos)
	fmt.Println(calcMetric(photos))
}
