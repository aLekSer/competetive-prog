#include <sstream>    
#include <iostream>
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
 
    int n, k;
 
    cin >> n >> k;
   //  ll t3 = pow(2, n-1);
    // cerr << t3 << endl;
    ll t = 1;
    const int ma = 5000000;
    //const int ma = 50;
    int it =  n / ma;
    int rest  = n  % ma;
 
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
     //cerr << t << endl;
    return 0;
}
