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
	cin >> n >> k ;
    
	vector<pair<int, int>> v;
	vector<pair<int, int>> v2;

	for (int i = 0; i < n; i++) {
		int q;
		cin >> q ;
		v.push_back(make_pair(q, i));

	}
	sort(v.begin(), v.end(),comp);
	ll res = 0;
	for (int i = 0; i < k; i++) {
		res += v[i].first;
		v2.push_back(make_pair(v[i].first, v[i].second));
	} 
	sort(v2.begin(), v2.end(), rev_cmp);
	cout << res << endl;
	if (k == 1) {
		cout << n;
		return 0;
	}
	cout << v2[0].second + 1 << " "; 
	if (k > 2) {
		for (int i = 1; i < k-1; i++) {
			cout << v2[i].second - v2[i-1].second << " "; 
		} 

	}
	cout << n - 1 - v2[k-2].second << " "; 
}

