#include <sstream>    
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 

//JUL18 EQUILIBR task
typedef __int128 ll;
// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y);
 
// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll res = 0;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
         res = (x%m + m) % m;
    }
    return res;
}
 
// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
const ll m = 1000000007;
 
int  main() {
    stringstream in( "2\n" 
                "2 4\n"
                "1 5\n"
                );
 
    int t;

    //nput begins with an integer T, the number of neighborhoods. For each neighborhood, there is first a line containing the space-separated
    // integers N and M. Then, N-1 lines follow. The ith of these lines contains the space-sep
    //arated integers Ai and Bi. Then, M lines follow. The ith of these lines contains the space-separated integers Yi and Hi. 
 
    cin >> t;


    ll left = 0;
    ll right = 0;
    for (int i = 0; i < t; i ++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n), l(n), r(n);
        vector<bool> v(n, false);
        vector<int> y(m), h(m);
        for (int j = 0; j < n-1; j ++) {
            cin >> a[j] >> b[j];
        }
        for (int j = 0; j < m; j ++) {
            cin >> y[j] >> h[j];
            v[y[j]] = true;
        }
        for (int j = 0; j < m; j ++) {
            cin >> y[j] >> h[j];
            v[y[j]] = true;
        }
        for (int j = 0; j < n; j ++) {
            if(!v[j]) {
                for (int k = 0 ; k < m ; k++) {
                    if (y[k] - 1 < j ) {
                        left = max(left, (ll)h[k]);
                    } else {
                        right = max(right,  (ll)h[k]);
                    }
                }

            }
        }
        
    }
    /*
    ll a1;
    ll part ;
    if (it > 0) {
        for (int i = 0; i < ma - 1; i ++) {
            t  *= 2;
        }
         a1 = modInverse(t, m);
         part = a1;
        for (int i = 1 ; i < it ; i ++) {
            part = (part * a1) % m;
        }
 
    } ll a = 1;
    if ( n > 50 ) {
     t = 1;
        
            t  *= 2;
        ll a12 = modInverse(t, m);
        cerr << (long long ) a12 << endl;
        for (int i = 0; i < rest - 1; i ++) {
            a = (a * a12) %  m;
        }
        ll d =   n;
        cerr <<  ( (long long ) d) << endl;
    cerr <<   ( (long long ) a ) << " " << ( (long long )(a * d))  << endl;
        if (it > 0) {
            a = (a * part ) % m;
        }
        ll res = (a * d ) % m;
        res = (1 - res) %m + m ;
        cout <<  ((long long )res)  << endl;
    }
    else {
        ll t = 1;
        for (int i = 0; i < rest - 1; i ++) {
            t = t * 2;
        }
        a = modInverse(t, m);
        ll d = t -  n;
        cerr <<  ( (long long ) d) << endl;
    cerr <<   ( (long long ) a ) << " " << ( (long long )(a * d))  << endl;
        if (it > 0) {
            a = (a * part ) % m;
        }
        ll res = (a * d ) % m;
        cout <<  ((long long )res)  << endl;
 
    }
    */
     //cerr << t << endl;
    return 0;
}
