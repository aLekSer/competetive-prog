#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//Task: NMNMX

using namespace std;
const int mod = 1000000007;
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
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		vector<long long> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < n; j++) {
			//cerr << v[j];
		}
		cout << combin(n, k, v) << endl;
	}
}

