#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

//Command to add debuging symbols for VS Code
// g++ -g -o ./a.out ./SHKSTR.cpp
typedef long long ll;
//Return the number of candies we need give
ll can(ll a, ll b, ll l) {
    return max<ll> (0, (a - l)* b);
}
bool cmp (pair<ll, ll > a, pair<ll, ll> b) {
    return a.first <  b.first;
}
int main() {
	// your code goes here
	ll N, M;
    cin >> N >> M;
	vector<ll> a(N), b(N);
    map<ll, ll, greater<ll>> m;
    ll sum = 0;
    bool overflow = false;
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	   // a.push_back(cc);
        a[i] = cc;
        /*
        sum += a[i];
        if (M < sum) {
        // cerr << sum ;
        overflow = true;
        }*/
	}
    /*
    if (!overflow) 
    {

            cout << 0 << endl;
            return 0;
    }*/
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	    //b.push_back(cc);
        b[i] = cc;
        //m.insert(make_pair(cc, i));
	}
    //sum = std::accumulate(a.begin(), a.end(), sum);

    ll left = M;
    ll mx =0;
    vector<pair<ll, ll>> x(N);
	for (int i = 0 ; i < N; i++)
	{
        ll c = can(a[i], b[i], 0);
        if (c > 0) {
            x[i].first = c;
            x[i].second = i;
        }
    }
    make_heap(x.begin(), x.end(), cmp);
    for (int i = 0 ; i < M;) {
        ll mx = x.front().first;
        ll id = x.front().second;
        pop_heap(x.begin(), x.end(), cmp);
        x.pop_back();
        ll mx2 = x.front().first;
        ll num_it = min((mx - mx2) / b[id] + 1, M  - i  ) ; 
        //cerr << num_it;
        if (mx == mx2) {
            num_it = 1;
        }
        mx -= b[id] * num_it;
        x[x.size()-1].first = mx;
        x[x.size()-1].second= id;
        push_heap(x.begin(), x.end(), cmp);
        i += num_it;

    }
    if (x.front().first < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cout << x.front().first << endl;
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