#include <iostream>
#include <iostream>
#include <sstream>    

using namespace std;

int main() {
int T; 
stringstream in( "2\n" 
            "2 4\n"
            "1 5\n"
             );

int N;

    //cin >> T;
    in >> T;
    for (int i = 0; i < T; i++) {
        unsigned long long A;
        unsigned long long B;
	in >> A >> B;
        //cin >> A >> B;
        // 3 op 
        // 1. write 0 bits  before a
        // 2. reorder bits
        // 3. add + 1
        // calc 1 binary symbols
        unsigned long long r = 0x1;
        int countE = 0;
        int countZ = 0;
	const int bits = 129;
        for (int i = 0 ; i < bits; i ++ ) {
            if (r & A ) {
                countE ++;
            }  else {
                countZ ++;
            }
            if (r > A) {
                break;
            }
            r = r << 1;
        }
        r = 0x1;
        int countEB = 0;
        int countZB = 0;
        for (int i = 0 ; i < bits; i ++ ) {
            if (r & (B - 1) ) {
                countEB ++;
            }  else {
                countZB ++;
            }
            if (r > B) {
                break;
            }
            r= r << 1;
        }
        if ( A == B ){
            cout << 0  << endl;
            continue;}
        if (A != 0 && B == 0) {
            cout << -1 << endl;
            continue;
        }
        if ( B == 1 )  {
            if (A == 0 ) cout <<  1 << endl; 
            else cout << -1 << endl; 
            continue;};
        int total = (countEB - countE) + 1;
        if(total <= 0)
           total = 2 ;// countEB + 1;
            cout << total << endl;
    }
}
