#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

//PDELIV

using namespace std;
const int mod = 1000000007;
typedef long long  ll; 
void comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) std::cout << " " << i;
        }
        std::cout << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

long long combin(int N, int K, vector<long long>& v)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
	long long res = 1;
    // print integers and permute bitmask
    do {
		bool skip_first = true;
		int count = 0;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) {
				if (skip_first)  
					skip_first = false;
				else if (count < K  - 2) {
					res *= v[i];
					res = res % mod;
					cerr << res;
					count ++;
				}
			} 
        }
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
	return res;
}

int main()
{
	int n = 0, m;
	cin >> n >> m;
	vector<ll> p(n), s(n);
	vector<ll> c(m), k(m);
	vector<set<int>> un(m, set<int>());

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> p[i];
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> c[i];
		cin >> k;
		for(int j =0; j < k; j ++) {
			int l;
			cin >> l;
			un[i].insert(l-1);
		}
	}
	for (int i = 0; i < m; i++) {
		long long min = 9223372036854775807;
		for (int j = 0; j < n; j++) {
			if (un[i].find(j) != un[i].end())
				continue;
			long long cur = (c[i] - s[j] )* (c[i] - s[j] ) + p[j];
				if (cur < min)
					min = cur;
		}
		cout << min << endl;
	}
}

