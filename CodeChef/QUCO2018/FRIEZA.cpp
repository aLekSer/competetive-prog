#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
  char myints[]= {'f','r','i','e','z','a'};
  std::set<char> second (myints,myints+6);
    for (int i = 0; i < T; i++) {
        int good = 0;
        int bad = 0;
        string s;
        cin >> s;
        bool prev = false;
        for (int j = 0; j < s.length(); j++ )
        {
            set<char>::iterator it = second.find(s[j]);
            if (it == second.end()) {
                if (j) {
                 if (!prev) {
                    cout << bad;
                    bad = 0;
                 }
                }
                good ++;
	      prev = true;
            } else {
                if (j) {
                 if (prev) {
                    cout << good;
                    good = 0;
                 }
                    
                }
                bad ++;
	      prev = false;
            }
        }
            if (bad)
                cout << bad;
                
            if (good)
                cout << good;
        
        
        cout << endl;
    }
	// your code goes here
	return 0;
}

