package main

import "testing"

func Test_cover(t *testing.T) {
	type args struct {
		r  int
		c  int
		vx []int
		vy []int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "ABC",
			args: args{
				r:  5,
				c:  5,
				vx: []int{0, 4, 0, 4},
				vy: []int{0, 0, 4, 4},
			},
			want: 2,
		},
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := cover(tt.args.r, tt.args.c, tt.args.vx, tt.args.vy); got != tt.want {
				t.Errorf("cover() = %v, want %v", got, tt.want)
			}
		})
	}
}
