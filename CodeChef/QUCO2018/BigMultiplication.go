package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	t := 0
	fmt.Scanf("%d", &t)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	//fmt.Println(t)
	for j := 0; j < t; j++ {
		//_, err := fmt.Scanf("%s %s", &s, &d) // this option is for small lines (generates unexpected new line)
		s := scanner.Text()
		scanner.Scan()
		d := scanner.Text()
		scanner.Scan()
		sSum := 0
		dSum := 0
		for i := 0; i < len(s); i++ {
			i, err := strconv.Atoi(string(s[i]))
			if err != nil {
				fmt.Println(err)
			}
			sSum += i
			sSum = sSum % 3
		}
		for i := 0; i < len(d); i++ {
			i, err := strconv.Atoi(string(d[i]))
			if err != nil {
				//fmt.Println(err)
			}
			dSum += i
			dSum = dSum % 3

		}
		//fmt.Println(sSum, " ", dSum)
		fmt.Println((sSum * dSum) % 3)

	}

}
