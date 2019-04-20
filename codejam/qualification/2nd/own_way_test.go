package main

import "testing"

func Test_cover(t *testing.T) {
	type args struct {
		r  string
	}
	tests := []struct {
		name string
		args args
		want string
	}{
		{
			name: "ABC",
			args: args{
				r:  "SEEE",
			},
			want: "ESSS",
		},
		// TODO: Add test cases.
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := cover(tt.args.r); got != tt.want {
				t.Errorf("cover() = %v, want %v", got, tt.want)
			}
		})
	}
}
