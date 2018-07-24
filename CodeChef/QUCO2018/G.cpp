#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
typedef __int128 d;
//Memoize
int main() {
    int T;
    cin >> T;
    // R,L,C,Vin
    unsigned long long R,L,C,Vin;
    for (int i = 0; i < T; i++) {
        cin >> R >> L >> C >> Vin;
        //unsigned long long tmp =( C  /(unsigned long long) 4 / L) * R * R * (unsigned long long)100;
        d tmp =1 - ((d) C  / 4 /(d) L) * (d)R * (d) R ;
        //long long mid = (long long)100 - tmp;
        //long double dd = mid;
        //cout << dd/(long double)100. << endl;
        /**/
        //if (tmp > 100)
        // printf("-");
        //printf("%lld",(tmp - 100)/(long long)100);
        //printf(".");
        //printf("%02d\n",(int)(llabs(tmp)%(long long)100));
	//cout << tmp;
	printf("%.2f", tmp);
        
	    //cout << B  << endl;
    }
//cout << "TEst " << primeFactors(6);
	// your code goes here
	return 0;
}

