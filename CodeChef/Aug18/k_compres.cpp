#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>

using namespace std;

typedef __uint128_t ll ;
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

ll ipow(ll base, ll exp, ll mod)
{
    ll result = 1;
    for (;;)
    {
        if (exp & 1) {
            result *= base;
            result = result % mod;
        }
        exp >>= 1;
        if (!exp)
            break;
        base =  (base * base) % mod;
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
        cerr << "1 " << (long long ) 2;
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
        cerr  << "2 " << (long long ) i;
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2) {
        res.push_back(n);
        cerr << "3 " <<(long long )  n;
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
        if ( l % pf[i] == 0) {
            l /= pf[i];
            res *= pf[i] ;
        }
    }
    return res;
	
	
}

std::ostream&
operator<<( std::ostream& dest, ll value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        ll tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

// gcd (a, b) == gcd( (a^N)% b, b)
int prepare(const vector<int> & a, int s) {
    vector<int> b = a;
    const int n = a.size();
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += a[j];        
    }
    if (sum < s) {
        return n;
    }
    vector<int> c(n, -1);
    int mid = 10000;
    for (int k = 0; k < n; k ++) {
            int mi = mid * 2;
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = max(0, j-k); i < min(n, j+k); i ++) {
                if (a[i] < a[j]) {
                    count ++;
                }
            }
            if (c[j] == -1)
                c[j] = mid;
            for (int i = max(0, j-k); i < min(n, j+k); i ++) {
                if (count > 0) {
                    c[i] = c[j] - 1;
                    count --;
                } else {
                    c[i] = c[j];
                }
                if (c[i] < mi) {
                    mi = c[i];
                }
            }
        }
        int sum2 = 0;
        for (int j = 0; j < n; j++) {
            cerr << (c[j] - mi + 1 )<< endl;
            sum2 += c[j] - mi + 1;
        }
        cerr << sum2 << endl;
    }
    

}
int main() 
{
    int t;
    cin >> t;
    for (int i = 0; i < t ; i++) {
        long long  n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i];
        }
        cout << (long long ) prepare(a, s) << endl;
    }
}

//Some test cases
/*
./mod
1
1999999 1999999 1999994
output: 0 ?
*/

