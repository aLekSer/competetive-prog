#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <set>
#include <map>

using namespace std;

//g++ -o ./pr -g ./princ_dr.cpp

bool comp(int a , int b)
{
    return a > b;
}

// Place 64 bytes of bit map of the tags to compare
    vector<vector<int> > f;
    map<string, int> t2;

void  tag(string s, int i , int j) 
{
    int p = t2[s];
    int r = p % 8;
    int c = p / 8;
    f[i][r] = f[i][r]  | 1 << c;
}
const int K = 64;
int countOnes(int i) {
    return ((i>>3)&1)+((i>>2)&1)+((i>>1)&1)+(i&1);
}
// calculate fitness function
int res(int i, int j, int k, int l)
{
    int com= 0;
    int diff = 0;
    for (int c = 0 ; c < K ; c ++) {
            int b = f[l][c] | f[k][c];
            int a = f[i][c] | f[j][c];
            diff += countOnes( a^ b ) ;
            com += countOnes(a & b );
    }
    if ( com == 0)
    {
        return 0;
    } else {
            return min(diff, com);
    }
}

int res(int i, int j, int k)
{
    int com= 0;
    int diff = 0;
        for (int c = 0 ; c < K ; c ++) {
            int b = f[j][c] | f[k][c];
            int a = f[i][c];
            diff += countOnes( a^ b ) ;
            com += countOnes(a & b );
        }
        if ( com == 0)
        {
            return 0;
        } else {
            return min(diff, com);
        }

    
}

int res(int i, int j)
{
    int com= 0;
    int diff = 0;

        for (int c = 0 ; c < K ; c ++) {
            diff += countOnes(f[i][c] ^ f[j][c]);
            com += countOnes(f[i][c] && f[j][c]);
        }
        if ( com == 0)
        {
            return 0;
        } else {
            return min(diff, com);
        }

}
int main() 
{
    int t;
    cin >> t;

    f = vector<vector<int> >(t, vector<int>(64, 0));
    vector<int> v(t);
    vector<bool> used(t);

    vector<vector<string> > s(t, vector<string>());
    int counter = 0;
    for (int i = 0; i < t; i++) {
        char o;
        int n;
        cin  >> o >> n;
        
        if (o == 'h') {
            v[i] = 1;
        } else {
            v[i] = 0;
        }
        for (int j = 0; j < n; j ++) {
            string st;
            cin >> st;
            s[i].push_back(st);
            
            if (t2.find(st) == t2.end())
                t2[st] = counter ++;
        }
    }

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < s[i].size(); j ++) {
            tag ( s[i][j], i, j);
        }
    }
    cout << t2.size() << endl;
    //number of iterations
    int m = 100 ;

    // Best solution
    int total = 0;
    int sum = 0;
    vector<vector <int> > sol;


    for (int i = 0; i < m; i ++) {
    vector<vector <int> > cur;
    set<bool> sel ; 
        for (int j = 0; j < t-3; j ++) {
            int el = rand() % t; 
            cur.push_back(vector<int>());
            while (true) {
                
                if (sel.find(el) != sel.end()) {
                    sel.insert(el);

                    cur[j].push_back(el);
                    //vert
                    if (v[el] == 0) {
                        while (true) {
                            int el2 = rand() % t;    
                            if (sel.find(el2) != sel.end() && v[el2] == 0) {
                                sel.insert(el2);
                                cur[j].push_back(el2);
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                    break;
                }
            }
            

        }



    }
    
    return 0;
} 
