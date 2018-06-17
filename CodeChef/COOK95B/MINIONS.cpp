#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

double aver( double prev, int pN, long long a ) {
	return prev * (pN-1)/pN + a/pN;
}
double rem ( double next, int pN, long long a) {
	return ( next - a / pN) *pN / (pN - 1);	
}
int main()
{
	// your code goes here
	int T ;
	cin >> T;
	vector<int > v(9, 0);
	//vector<bool > a(9, false);
	vector<string> ps;
	string number = "2134";
	sort(number.begin(), number.end());



	/*
	do cout << "Permutation: " << number << endl;

	while (next_permutation(number.begin(),number.end()));
	*/
	for (int i = 0 ; i < T; i++) {
int total = 0;
	    int  k, n;
	    cin >> n;
vector<long long > a;
vector<long long > b;
	long long  min = 100000000;
	int pos = 0;
	double mean = 0;
	//int N = 0;
	long long max = 0; 
	int pm = 0;
	    vector< pair <int, int> > e;
	    for (int j = 0 ; j < n ; j ++) {
			int a1 , b1;
	        cin >> a1 >> b1;
			a.push_back(a1);
			if (a1 < min) {
				min = a1;
				pos = j;
			}
			if (b1 > max) {
				max = b1;
				pm = j;
			}
			mean = aver(mean, j+1, a1);

			b.push_back(b1);
			e.push_back(make_pair(b1, j));
	    }
			vector<long long > c = a;
			vector<long long > d = b;
			sort(c.begin(), c.end());
			sort(d.begin(), d.end());
			sort(e.begin(), e.end());
		int N = n;
		if (double(min) < mean )
			cout << n << endl;
		else {
	    //int res = 0;
		    mean = rem(mean,  N, max);
			N--;
		if (double(min) < mean && pm != pos) {
			cout << n << endl; }
			while (N > 0) {

		    mean = rem(mean,  N, max);
			N--;
			if (double(min) < mean && pm != pos) {
				cout << n << endl; }

			}


			

		}
	}
	return 0;
}

