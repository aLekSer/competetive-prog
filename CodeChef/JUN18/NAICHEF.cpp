#include <iostream>
using namespace std;

int main() {
// your code goes here
int T;
cin >> T;
for (int i = 0; i < T; i ++) {
	int N, A, B;
	cin >> N >> A >> B;
	int totalA = 0;
	int totalB = 0;
	for (int j = 0; j < N; j++) {
	    int x;
	    cin >> x;
	    if (x == A) {
		totalA ++;
	    }
	    if (x == B) {
		totalB ++;
	    }
	}
	if ( A == B) {
	    totalB ;
	}
	cout << (double(totalA) / N) *  (double(totalB) / (N)) << endl;
    
	}
	return 0;
}

