#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

//Command to add debuging symbols for VS Code
// g++ -g -o ./a.out ./SHKSTR.cpp
typedef long long ll;
//Return the number of candies we need give
ll can(ll a, ll b, ll l) {
    return max<ll> (0, (a - l)* b);
}
int main() {
	// your code goes here
	ll N, M;
    cin >> N >> M;
	vector<ll> a, b;
    map<ll, ll, greater<ll>> m;
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	    a.push_back(cc);
	}
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	    b.push_back(cc);
        m.insert(make_pair(cc, i));
	}
    ll left = M;
    ll mx =0;
    vector<pair<ll, ll>> x;
	for (int i = 0 ; i < N; i++)
	{
        x.push_back(make_pair(can(a[i], b[i], 0), i));
    }
    make_heap(x.begin(), x.end());
    for (int i = 0 ; i < M; i ++) {
        ll mx = x.front().first;
        mx -= b[x.front().second];
        ll id = x.front().second;
        pop_heap(x.begin(), x.end());
        x.pop_back();
        x.push_back(make_pair(mx,id));
        push_heap(x.begin(), x.end());

    }
    cout << x.front().first;
    /*
	for (map<ll, ll>::iterator i = m.begin(); i != m.end(); i++)
	{
        cerr << i->first <<  " " <<  i->second << endl;
        left -= a[i->second];
        if (left < 0 ) {
            left += a[i->second];
            ll c = can(a[i->second], b[i->second], left);
            cerr << c << endl;
            mx = max(c, mx);
            left = 0;
        } else if (left == 0) {
            ll c = can(a[i->second], b[i->second], left);
            cerr << c  << endl;
            mx = max(c, mx);
        }
    }*/
   // cout << mx;
    
}