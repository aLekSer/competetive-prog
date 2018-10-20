#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;


//Problem Code in Oct18A HMAPPY

typedef uint64_t ll;
//Return the number of candies we need give
ll can(ll a, ll b, ll l) {
    return max<ll> (0, (a - l)* b);
}
bool cmp (pair<ll, ll > a, pair<ll, ll> b) {
    return a.first <  b.first;
} 

//Trying to solve the problem using binary search

void func2() {
	ll N, M;
    cin >> N >> M;
	vector<ll> a(N), b(N);
    //map<ll, ll, greater<ll>> m;
    ll sum = 0;
    bool overflow = false;

	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	   // a.push_back(cc);
        a[i] = cc;
        //sum += a[i];
	}
    
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	   // a.push_back(cc);
        b[i] = cc;
        //sum += b[i];
	}
    
    /*
    if (!overflow) 
    {

            cout << 0 << endl;
            return 0;
    }*/
    ll l = 0; ll r = 1e18;
    double v = 0;
    ll sum2 = 0;
    ll m = 0;
    while (l < r) {
        m = ll(l + (r - l) / 2);
        //check
        bool res = true;
        ll sum = 0;
        for (int i = 0; i < N; i ++)
        {
            if (!b[i])
                continue;
            if (a[i] * b[i] <= m)
                continue;
            if (((a[i] * b[i] - m) % b[i]  ) == 0)
                sum +=  ll ((a[i] * b[i] - m) / b[i]);

            else
                sum +=  ll ((a[i] * b[i] - m) / b[i]) + 1;
            if (sum > M ) {
                res = false;
                break;
            }
        }
        if (!res)
            l = m+1;
        else 
            r = m;
        
    }
    cout << l << endl;
}
int main() {
    func2();
	// your code goes here
   
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