#include "vector"
#include <iostream>

using namespace std;

bool inR(int a) {
    int x = a % 10;
    return x == 2 || x == 3 || x == 9; 
}
typedef long ll;
long long  alg1(long long n, long long k, string & s)
{
    long long dup = 0;
    int d =  1 ; //-1;
    for (ll i = 0 ; i < k - 1 ; i++) { // - k + 1; i++) {
        if (s[i + 1] == s[i] ) {
            dup += i + 1;
            s[i] = ' ';
        }
    }
    for (ll i = k - 1; i < n - k -1; i++) { // - k + 1; i++) {
        if (s[i] != ' ' &&  s[i + 1] == s[i] ) {
            dup += k;
            s[i] = ' ';
        }
    }
    int l2 = k;
    for (ll i = n - k - 1 ; i < n - 1; i++) { // - k + 1; i++) {
        //cerr << s[i];
        if (s[i] != ' ' && s[i + 1] == s[i] ) {
            dup += l2;
        }
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
	    cout << alg1(n, k, s) << endl;
	}
return 0;

}