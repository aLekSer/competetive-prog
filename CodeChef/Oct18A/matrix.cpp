#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;



typedef long long ll;
int c(vector<vector<ll>> & a, int ll, int r, int b, int c) {
    set<int> rows;
    int count = 0;
    for (int i = ll ; i < r + 1  ; i ++ )
    {
        for (int l = i + 1; l < r +1; l ++ )
        {
            for (int j = b ; j < c +1 ; j ++ )
            {

                if (a[i][j] != a[l][j]) {
                    rows.insert(i);
                    rows.insert(l);
                    break;
                }
            }
        }}
    return rows.size() == 0?1  :  rows.size();
}
int main() {
	ll N, M;
    cin >> N >> M;
	vector<vector<ll>> a(N, vector<ll> (M));
    for (int i = 0 ; i < N ; i ++ )
    {
        for (int j = 0 ; j < M ; j ++ )
        {
            ll c;
            cin >> c;
            a[i][j] = c;
        }
    }
    ll  count = 0;
    for (int i = 0 ; i < N ; i ++ )
    {
        for (int j = 0 ; j < M ; j ++ )
        {
            for (int l = i; l < N ; l ++ )
            {
                for (int k = j ; k < M ; k++ )
                {
                    count += c(a, i, l,j,k);
                }
            }
        }
    }
    c(a, 0, 1,0,1);
    cout << count << endl;
    return 0;
}