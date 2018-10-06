#include <iostream>
#include <vector>
using namespace std;

//Command to add debuging symbols for VS Code
// g++ -g -o ./a.out ./SHKSTR.cpp

typedef long long ll;
ll digsum(ll a) {
    ll sum = 0;
    while (a > 00) {
        sum += a %10;
        a /= 10;
    }
    return sum;
}
const ll iters = 1000; 
void findMin(ll n, ll d, ll & mn, ll & op) {
    mn = n;
    op = 0;
    for (int i = 0; i < iters; i ++) {
        ll n1 = n;
        for (int j = 0; j < iters; j ++) {
            n1 = digsum(n1);
            if ( n1 < mn ) {
                mn = n1;
                op = i + j + 1;
            }
        }
        n += d;
    } 
}

int main() {
	// your code goes here
	int T;
    cin >> T;
	for (int i = 0 ; i < T; i++)
	{
	    ll n, d;
	    cin >> n >> d;
        ll mn = 10e10;
        ll op = 0;
        findMin(n , d, mn, op );
        cout << mn << " " << op << endl;
	}
    return 0;
}