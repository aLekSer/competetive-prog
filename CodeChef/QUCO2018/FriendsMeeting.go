package main

import (
	"bufio"
	"fmt"
	"os"
)

//Eratosphene
var er []bool

func Init() {
	er = make([]bool, 102)

	er[0] = false
	er[1] = false
	for j := 2; j < 101; j++ {
		er[j] = true
	}
	res := 0
	for j := 2; j < 101; j++ {
		res = j
		for res+j < 101 {
			res += j
			er[res] = false
		}
	}
}

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	// STDOUT MUST BE FLUSHED MANUALLY!!!
	defer writer.Flush()

	t := 0
	Init()
	scanf("%d\n", &t)

	/*
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Split(bufio.ScanWords)
		scanner.Scan()
	*/

	//fmt.Println(t)
	for j := 0; j < t; j++ {
		//_, err := fmt.Scanf("%s %s", &s, &d) // this option is for small lines (generates unexpected new line)
		n := 0

		scanf("%d\n", &n)
		//fmt.Println(n)
		min := 1000
		foundOne := false
		for k := 0; k < n; k++ {
			a := 0
			scanf("%d ", &a)
			//printf("a%d", a)
			if a == 1 {
				foundOne = true
			}
			if er[a] && a < min {
				min = a
			}

		}
		if foundOne && min != 1000 {
			printf("%d\n", min)
		} else {
			printf("%d\n", -1)
		}
		//fmt.Println(sSum, " ", dSum)

	}

}
