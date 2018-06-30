#include "vector"
#include <iostream>

using namespace std;

// 1 6 5 aaaaaa
typedef long ll;
long long  alg1(ll n, ll k, string & s)
{
    long long dup = 0;
    int d =  1 ; //-1;
    for (ll i = 0 ; i < k - 1 ; i++) { // - k + 1; i++) {
        if (s[i + 1] == s[i] ) {
            dup += min(n-k, i + 1);
            s[i] = ' ';
        }
        cerr << i + 1 << endl;
    }
    for (ll i = k - 1; i < n - k -1; i++) { // - k + 1; i++) {
        if (s[i] != ' ' &&  s[i + 1] == s[i] ) {
            dup += min(n-k, k);
            s[i] = ' ';
        }
        if (s[i] != ' ' )
        cerr << k  << endl;
    }
    int l2 = k;
    for (ll i = n - k - 1 ; i < n - 1; i++) { // - k + 1; i++) {
        //cerr << s[i];
        if (s[i] != ' ' && s[i + 1] == s[i] ) {
            dup += min(n-k, l2);
        }
        if (s[i] != ' ' )
        cerr << l2  << endl;
        l2 --;
    }
    //cerr << " H " << dup;
    long long l = (long long)(n - k ) * k - dup;
    return l;
}
int main() 
{
    int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
	    int n, k;
	    cin >> n >> k; 
        string s;
        cin >> s;
        //getline(cin, s);
	    cout << alg1(n, k, s) << endl;
	}
return 0;

}