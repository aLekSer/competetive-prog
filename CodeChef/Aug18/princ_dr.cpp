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
        
    vector<int> res1;
    vector<int> res2;
        int n, p;
        cin  >> n >> p;
        vector<int> s(n);
        for (int j = 0; j < n; j ++) {
            cin >> s[j];
        }
        sort(s.begin(), s.end(), comp); 
            // Solution to compare
            vector<int> v3 ;
            vector<int> v2 = s;
            /*
        */
        for (int j = 0; j < n; j ++) {
            vector<int> v (n, -1);
            
            int ma = 0;
            do {
                int r = 0;
                   for (int ii = 0; ii < n; ii++) {
                        long long sum = 0;
                       for (int h = min(ii, j); h <= max(ii, j); h ++ ) {
                        sum += v2[h];
                       }
                        if (sum >= p) {
                            r ++;
                        }

                   }
                   if (r > ma) {
                       ma = r;
                       v3 = v2;
                   }

            } while (std::next_permutation(v2.begin(), v2.end()));
            if (ma == 0) {
                cout << 0 << " ";
                res1.push_back(0);
            } else {
                cout << ma << " ";
                res1.push_back(ma);
            }
            //cerr << "Here";
        }
        cout << endl;
       //     cout << "Right sol "  << endl;
            //End of solution to compare
            int temp = 0;
        for (int j = 0; j < n; j ++) {
            bool found = false;
            long long sum = 0;
            int l = max(n - j, j+1);
            /*
            for (int k = 0; k < l; k ++) {
               sum += s[k];
               if (sum >= p) { */
                   int r = 0;
                   int sign = +1;
                   if (j >= n/2) {
                       sign = -1;
                   }
                   long long  su = 0;
                   int total_used = 0;
                    for (int h = 0; h < n; h ++) {
                        int sh = (sign *h+j)% n;
                        if (sh < 0) {
                            sh += n;
                        }
                        //cerr << sh << " a " << endl;
                        v[sh] = s[h];
                        su += v[sh];
                        if (su >= p) {
                            sign = -1 *sign;
                            total_used = h;
                            break;
                        }
                    }
                    for (int h = 1; h < n - total_used; h ++) {
                        int sh = (sign *h+j)% n;
                        if (sh < 0) {
                            sh += n;
                        }
                        //cerr << sh << " a " << endl;
                        v[sh] = s[h + total_used ];
                        su += v[sh];
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
                   cout << r << " ";
                   temp = r;
                res2.push_back(r);
                   found = true;
                   //break;
/*
               }
            }*/
            break;
            if (!found) {
                cout << 0 << " ";
                res2.push_back(0);
            }
               //* /
        }         
        int t = temp;
            if (temp == 0) {
                
                for (int l = 1; l < n ; l++) {
                    cout << 0 << " ";
                }
            } else {
                
            if (temp == n) {
                for (int l = 1; l < n ; l++) {
                    cout << n << " ";
                }
            } else {
                
                for (int l =  1; l <  n/2 + 1 ; l++) {   
                        cout << max(0, --t) << " " ;
                        res2.push_back( max(0, --t) );
                }
                for (int l =   n/2 + 1 ; l < n; l++) {   
                    cout << res2[n - l];
                }
            }
        }
        cout << endl;
        if (!(res1 == res2) ) {
           // cout << "Error missmatch";
        }
    }
    return 0;
}

/* Bug: Examples of sigabrt
1 5 5
23200 233300 234250 23425151 235 1 6160

Solution to compare
1 8 20

2 2 3 4 4 3 2 2
Should be:
2 0 0 0 0 0 1 1
But for now
2 1 0 0 0 0 1 2

Try 2
8 125 12 31 71 51 12 2 2 2
1 1 1
*/