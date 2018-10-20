#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;

typedef uint64_t ll;
//Return the number of candies we need give
ll can(ll a, ll b, ll l) {
    return max<ll> (0, (a - l)* b);
}
bool cmp (pair<ll, ll > a, pair<ll, ll> b) {
    return a.first <  b.first;
} 

void func1() {
	ll N, M;
    cin >> N >> M;
	vector<ll> a(N), b(N);
    map<ll, ll, greater<ll>> m;
    ll sum = 0;
    bool overflow = false;
    ll maxA = 0;
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	   // a.push_back(cc);
        a[i] = cc;
        sum += a[i];
        if (M < sum) {
        // cerr << sum ;
            overflow = true;
        }
	}
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	    //b.push_back(cc);
        b[i] = cc;
        if (a[i]*b[i]> maxA)
            maxA =a [i]*b[i];
        //m.insert(make_pair(cc, i));
	}
    //sum = std::accumulate(a.begin(), a.end(), sum);
    if (!overflow) 
    {

            cout << 0 << endl;
            return;
    }
    if (sum - M < M) {
        cerr << "here";
        vector<pair<ll, ll>> x;
        x.reserve(N);
        for (int i = 0 ; i < N; i++)
        {
                x.push_back(make_pair( 0, i));
        }
        make_heap(b.begin(), b.end());
        for (int i = 0 ; i < sum - M; i ++) {
            pop_heap(b.begin(), b.end());
            ll mx = b.back();
            b.pop_back();
            b.push_back((mx));
            push_heap(x.begin(), x.end(), cmp);

        }
        cout << b.front() << endl;

        return;
    }

    ll left = M;
    ll mx =0;
    vector<pair<ll, ll>> x;
    x.reserve(N);
	for (int i = 0 ; i < N; i++)
	{
        if (a[i]*b[i] > (double(maxA) / 20.)) {
            x.push_back(make_pair( a[i]*b[i], i));
        }
    }
    cerr << x.size() <<  " " << double(maxA) / 3. << endl;
    make_heap(x.begin(), x.end(), cmp);
    for (int i = 0 ; i < M;) {
        pop_heap(x.begin(), x.end(), cmp);
        ll mx = x.back().first;
        ll id = x.back().second;
        x.pop_back();
        ll mx2 = x.front().first;
        ll num_it = min((mx - mx2) / b[id] + 1, M  - i  ) ; 
        //cerr << num_it;
        if (mx == mx2) {
            num_it = 1;
        }
        mx -= b[id] * num_it;
        x.push_back(make_pair(mx,id));
        push_heap(x.begin(), x.end(), cmp);
        i += num_it;

    }
        pop_heap(x.begin(), x.end(), cmp);
    if (x.back().first < 0)
    {
        cout << 0 << endl;
        return;
    }
    cout << x.back().first << endl;
}
void func2() {
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
        sum += a[i];
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
    double v = 0;
    ll sum2 = 0;
	for (int i = 0 ; i < N; i++)
	{
	    ll cc;
	    cin >> cc;
	    //b.push_back(cc);
        b[i] = cc;
        v += 1./ double(b[i]);
        //m.insert(make_pair(cc, i));
	}
    cerr << (sum - M)/ v; 
}
int main() {
    func1();
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