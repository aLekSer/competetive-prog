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
    for (int i = ll ; i < r - 1 ; i ++ )
    {
        for (int j = b ; j < c ; j ++ )
        {
            for (int l = i + 1; l < r ; l ++ )
            {

                if (a[i][j] != a[l][j]) {
                    rows.insert(i);
                    rows.insert(l);
                }
            }
        }}
    return rows.size() == 0? rows.size() : 1;
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
    cout << count << endl;
    return 0;
}