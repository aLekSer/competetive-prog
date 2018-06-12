#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//Memoize
vector<int> fact;
int primeFactors(int n)
{
    int count = 0;
	int N = n;
    bool found = false;
    if (n == 1) 
	return 0;
    while (n%2 == 0)
    {
        if (!found) {
            found = true;
//cout << "Here";
            count ++;
        }
        n = n/2;
    }
//cout << n << endl;
//cout <<  " sdf "<< sqrt(N);
   if (n < 10000 && fact[n] != -1) {
//cout << "Here";
	return count + fact[n];
   }
    for (int i = 3; i <= sqrt(N) + 1; i = i+2)
    {
    	found = false;
 //cout << i << "T2" << endl;
        while (n%i == 0)
        {
//cout << "Here";
		if (!found) {
		    found = true;
		    count ++;
		}
            n = n/i;
        }
    }
     if (n > 2)
	count ++; 
   if (N < 10000)
    fact[N] = count;
    return count;
}
int main() {
    int T;
    cin >> T;

fact = vector<int>(10001, -1);
    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;
        int total = 0;
        for (int j = n; j < m; j++) {
            total += primeFactors(j);
//cout << j << " " << primeFactors(j);
        }
	    cout << total << endl;
    }
//cout << "TEst " << primeFactors(6);
	// your code goes here
	return 0;
}

