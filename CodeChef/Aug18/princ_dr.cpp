#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

//g++ -o ./pr -g ./princ_dr.cpp

bool comp(int a , int b)
{
    return a > b;
}
int main() 
{
    int t;
    cin >> t;
    vector<int> v(20001);
    for (int i = 0; i < t; i++) {
        
        int n, p;
        cin  >> n >> p;
        vector<int> s(n);
        for (int j = 0; j < n; j ++) {
            cin >> s[j];
        }
        sort(s.begin(), s.end(), comp); 
        v = s;  
        for (int j = 0; j < n; j ++) {
            int ma = 0;
            do {
                int r = 0;
                   for (int ii = 0; ii < n; ii++) {
                        long long sum = 0;
                       for (int h = min(ii, j); h <= max(ii, j); h ++ ) {
                        sum += v[h];
                       }
                        if (sum >= p) {
                            r ++;
                        }

                   }
                   if (r > ma) {
                       ma = r;
                   }

            } while (std::next_permutation(v.begin(), v.end()));
            if (ma == 0) {
                cout << 0 << " ";
            } else {
                cout << ma << " ";
            }
            /*
            cerr << "Here";
            bool found = false;
            long long sum = 0;
            int l = max(n - j, j+1);
            for (int k = 0; k < l; k ++) {
               sum += s[k];
               if (sum >= p) {
                   int r = 0;
                   int sign = +1;
                   if (j >= n/2) {
                       sign = -1;

                   }
                    for (int h = 0; h < n; h ++) {
                        int sh = (sign *h+j)% n;
                        if (sh < 0) {
                            sh += n;
                        }
                        cerr << sh << " a " << endl;
                        v[sh] = s[h];
                    }
                   for (int ii = 0; ii < n; ii++) {
                        long long sum = 0;
                       for (int h = min(ii, j); h <= max(ii, j); h ++ ) {
                        sum += v[h];
                       }
                        if (sum >= p) {
                            r ++;
                        }

                   }
                   /*
                   if (j < n / 2) {
                   } else  {
                    cout << j - k + 1 << " ";
                   }* /
                   cout << r << " ";
                   found = true;
                   break;

               }
            }
            if (!found) {
                cout << 0 << " ";
            }
               */
        }         
        cout << endl;
    }
    return 0;
}

/* Bug: Examples of sigabrt
1 5 5
23200 233300 234250 23425151 235 1 6160

*/