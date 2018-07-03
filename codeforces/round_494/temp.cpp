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
long long  avg(vector<int> & a, int i,  int j) {
	long long res = 0;
	for (int d = i; d < j; d ++) {
		res += (a[d]) ;
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
	long long av = 0;
	double max_a = 0.;
	cout.precision(17);
	for (int i = 0; i < n; i ++) {
	    if (i + k <= n) {
		 	av = avg(a, i , i + k);
		} else {
			 break;
		}
		if (((double )av/ (double)  (k) ) > max_a) {
			max_a = ((double )av/ (double)  (k ) );
		}
		for(int j = i+k; j < n; j ++) {
			av = ( av  + a[j]) ; ;
			if (( (double )av  / (double)(j - i + 2) )> max_a) {
				max_a = ( (double )av  / (double)(j - i +2	) );
			}
		}
	}
	cout << max_a << endl;
	return 0;
}

