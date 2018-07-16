#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

//PDELIV
typedef  long long ll;
using namespace std;
int comp (pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}
int rev_cmp (pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main()
{
	int n = 0, k;
	cin >> n  ;
    
	vector<ll> v, s(n), e(n);

	for (int i = 0; i < n; i++) {
		ll q;
		cin >> q ;
		v.push_back(q);

	}
	s[0] = v[0];
	e[0] = v[n-1];
	for (int i = 1; i < n; i++) {
		s[i] = s[i-1] + v[i];
		e[i] =  v[n-1-i] + e[i -1];
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if ((s[i] == e[j]) && s[i] > max)
				max = s[i];
		}
	}

	cout << max << " "; 
}

