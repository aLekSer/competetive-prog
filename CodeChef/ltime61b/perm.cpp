#include "vector"
#include <iostream>

using namespace std;

// 1 6 5 aaaaaa
typedef long ll;
/*The first line of each test case contains two space-separated integers N and M
.
N
lines follow. For each valid i, the i-th of these lines contains M space-separated integers Pi,1,Pi,2,…,Pi,M denoting the permutation Pi
.
The next line contains a single integer Q
.
Each of the following Q
lines contains two space-separated integers L and R describing one query.
*/
vector<vector<ll>> res;
vector<int> mul (vector<int>& x, vector<int> &y) {
    vector<int> r(x.size());
    for(int i = 0; i < x.size(); i++) {
        r[i] = y[x[i] - 1];
    }
    return r;
}
long long  alg1(ll n, ll m)
{
    long long s = 0;
    vector<vector<int>> p(n, vector<int>(m));
    for (ll i = 0 ; i < n; i++) { // - k + 1; i++) {
        for (ll j = 0; j < m ; j++ ) {
        cin >> p[i][j];

        }
    }
    int q;
    cin  >> q;
    for (int i = 0; i < q; i++) {
        int l , r;
        cin >> l >> r;
        vector<int> res;
        if (l != r ) {
            res = mul(p[l-1], p[l]);
        for (int j = l+2; j <= r; j ++) {
            res = mul(res, p[j-1]);
        }
        }  else res = p[l-1];

        for (int k = 1 ; k <= m ; k ++) {
            s += k * res[k-1];
        }
        cout << s << endl;
        s = 0;
        //B=PL⋅PL+1⋅…⋅PR
    }

return s;
}
int main() 
{
    int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
	    int n, m;
	    cin >> n >> m;
          alg1(n, m);
        //getline(cin, s);
	   // cout << " 1asdf " << alg1(n, m) << endl;
	}
return 0;

}