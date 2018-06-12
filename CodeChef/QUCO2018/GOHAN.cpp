#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//Memoize
int main() {
    int T;
    cin >> T;
    // R,L,C,Vin
    unsigned long long R,L,C,Vin;
    for (int i = 0; i < T; i++) {
        cin >> R >> L >> C >> Vin;
        unsigned long long tmp =( C  /(unsigned long long) 4 / L) * R * R * (unsigned long long)100;
        //long long mid = (long long)100 - tmp;
        //long double dd = mid;
        //cout << dd/(long double)100. << endl;
        /**/
        if (tmp > 100)
         printf("-");
        printf("%lld",(tmp - 100)/(long long)100);
        printf(".");
        printf("%02d\n",(int)(llabs(tmp)%(long long)100));
        
        
	    //cout << B  << endl;
    }
//cout << "TEst " << primeFactors(6);
	// your code goes here
	return 0;
}

