#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
//Memoize
int main() {
    int T;
    cin >> T;
    // R,L,C,Vin
    double R,L,C,Vin;
    for (int i = 0; i < T; i++) {
        cin >> R >> L >> C>> Vin;
        double B = 1 - C * C * R * R/ 4 / L;
        
	    cout << B * Vin << endl;
    }
//cout << "TEst " << primeFactors(6);
	// your code goes here
	return 0;
}

