#include <iostream>
#include <string>
#include "stdlib.h"
#include <stdio.h>
#include <vector>
using namespace std;


template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
         cin >>  v[i];
}
double avg(vector<int> & a, int i,  int j) {
	double res = 0;
	for (int d = i; d < j; d ++) {
		res += (double) (a[d]) / (double)  (j - i );
	}
	return res;
}
int main() {
// your code goes here
	int n , k;
	cin >> n >> k;
	string s = "";
	vector<int> a(n);
	getVector<int>(a);
	int b1;
	double max_a = 0.;
	for (int i = 0; i < n; i ++) {
		double av = avg(a, i , i + k);
		if (av > max_a) {
			max_a = av;
		}
		for(int j = i+k; j < n; j ++) {
			av = ( av *  (j - i ) +(double) a[j]) / (double)(j - i + 2	);
			if (av > max_a) {
				max_a = av;
			}
		}
	}
	cout << max_a << endl;
	return 0;
}

