#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
vector<vector <int>> board;
long long combin(int N, int K)
{
    if (N < K) 
        return 0;
    if (K <= 0)
        return 1;
    if (K == 1) {
        return N;
    }
	long long res = 1;
		int count = 1;
    // print integers and permute bitmask
    // 6 
    // edge cells not always 4 
    
    count = min(4, N) * combin(N - 3, K - 1 ) + max ((N - 4), 0) * combin(N - 4, K - 1);
	return count;
}
long long combi(int N, int K);
long long combi2(int N, int K)
{
	long long res = 1;
    int count = 0;
    if ( K == N && N == 1 ) {
        return 1;
    } 
    if (K> N ) 
     {
        return 0;
    }
    if (K == 0 )
        return 1;
    if (N == 0 && K > 0) {
        return 0;
    }
    // print integers and permute bitmask
    // 6 
    // edge cells not always 4 
    count = (combi2(N-1, K - 1) + combi(N-1, K)) %mod;
	return count;
}
long long combi(int N, int K)
{
	long long res = 1;
    int count = 0;
    if ( K == N && N == 1 ) {
        return 2;
    }
    if (K> N ) 
     {
        return 0;
    }
    if (N == 0 && K > 0) {
        return 0;
    }
    if (K == 0  )
        return 1;
    // print integers and permute bitmask
    // 6 
    // edge cells not always 4 
    count = (2 * combi2(N-1, K - 1) + combi(N-1, K)) %mod;
	return count;
}
int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
        board = vector<vector<int>> (n, vector<int>(2, 0));
		for (int j = 0; j < n; j++) {
			//cerr << v[j];
		}
		cout << combi(n, k) << endl;
	}
}