/*
// Sample code to perform I/O:

me;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<int> a , b, c;
        for (int j = 0; j < n; j++) {
            int l ;
            cin >> l;
            a.push_back(l);
            c.push_back(l);
        }
        for (int j = 0; j < n; j++) {
            int l ;
            cin >> l;
            b.push_back(l);
            c.push_back(l);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int med = c[c.size()/2];
        int count = 0;
        while (a[a.size()/2] != b[b.size()/2]) {
            count ++;
            if (count > a.size() - 1) {
                cout << -1 << endl ;
                return 0;
            }
            bool m2 = b[b.size()/2] > med;
            bool m = a[a.size()/2] > med;
            if (m )
            {
                int c = b[count];
                b[count] = a[b.size() - count];
                a[b.size() - count] = c;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
            } else {
                int c = a[count];
                a[count] = b[b.size() - count];
                b[b.size() - count] = c;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
            }
                
        }
        cout << count << endl ;
    }
}
