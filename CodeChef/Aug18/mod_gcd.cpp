#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>

using namespace std;

typedef __int128 ll ;
const int MOD=1000000007;
ll ipow(ll base, ll exp)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

 
// A function to print all prime factors of a given number n
vector<ll> primeFactors(ll n)
{
    vector<ll> res;
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        res.push_back(2);
        cerr << " " << (long long ) 2;
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            res.push_back(i);
        cerr  << " " << (long long ) i;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2) {
        res.push_back(n);
        cerr << " " <<(long long )  n;
    }
    return res;
}

ll gcd (ll l, ll r)
{
    if (l == 0 || r == 0)
    {
        return max(l, r);
    }
    ll res = 1;
	//Find prime factors of the smaller number
	vector<ll> pf = primeFactors(r);
    for (ll i = 0; i < pf.size(); i++) {
        if ( l % pf[i] == 0)
            res *= pf[i] ;
    }
    return res;
	
	
}
ll prepare(ll a, ll b, ll n) {
	auto res = gcd(ipow(a, n) + ipow(b,n), abs(a - b));
	return res % MOD;
}
int main() 
{
    int t;
    cin >> t;
    for (int i = 0; i < t ; i++) {
        long long  a, b, n;
        cin >> a >> b >> n;
        cout << (long long ) prepare(a, b , n) << endl;
    }
}