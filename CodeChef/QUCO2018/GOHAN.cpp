#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//Memoize
int main() {
    int T;
    cin >> T;
    // R,L,C,Vin
    long long R,L,C,Vin;
    for (int i = 0; i < T; i++) {
        cin >> R >> L >> C >> Vin;
        long long mid = (long long)100 - (C * (long long)100 /(long long) 4 / L )* R * R ;
        printf("%lld",mid/(long long)100);
        printf(".");
        printf("%2d\n",(int)(llabs(mid)%(long long)100));
        
	    //cout << B  << endl;
    }
//cout << "TEst " << primeFactors(6);
	// your code goes here
	return 0;
}

