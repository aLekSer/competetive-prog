#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <set>
#include <map>
#include <fstream>

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

int count (vector<int> a, vector<int> b) {
    if ((a.size() == 2 )&& (b.size() == 2)) {
        return res(a[0], a[1], b[0], b[1]);
    }

    if (a.size() == 1 && b.size() == 2) {
        return res(a[0], b[0], b[1]);
    }

    if (a.size() == 1 && b.size() == 1) {
        return res(a[0], b[0]);
    }
    if (a.size() == 1 && b.size() == 1) {
        return res(a[0], b[0]);
    }
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
            // a + b - (a&& b)
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
int main(int argc,char *argv[])
{
    fstream ci ;
   ci.open(string(argv[1]), ios::out | ios::in );
    //ci.open("a_example.txt", ios::out | ios::in );
    fstream fo ;
    fo.open("results.txt", ios::out | ios::in );
    int t;
    ci >> t;
    cout << t;


    f = vector<vector<int> >(t, vector<int>(64, 0));
    vector<int> rot(t,0);
    vector<bool> used(t);

    vector<vector<string> > s(t, vector<string>());
    int counter = 0;
    for (int i = 0; i < t; i++) {
        char o;
        int n;
        ci  >> o >> n;
        
        if (o == 'H') {
            rot[i] = 1;
        } else {
            rot[i] = 0;
        }
        for (int j = 0; j < n; j ++) {
            string st;
            ci >> st;
            s[i].push_back(st);
            
            if (t2.find(st) == t2.end())
                t2[st] = counter ++;
        }
    }

/**/
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < s[i].size(); j ++) {
            tag ( s[i][j], i, j);
        }
    }
    cout << t2.size() << endl;
    //number of iterations
    int m = 1 ;

    // Best solution
    int total = 0;
    int sum = 0;
    vector<vector <int> > sol;

    /*
    for (int j = 0; j < t; j ++)
    {
        cout << "ou" << rot[j] <<endl;
    }
    */
    for (int i = 0; i < m; i ++) {
        vector<vector <int> > cur;
        set<int> sel ; 
        for (int j = 0; j < t- 1; j ++) {
            while (true) {
            int el = rand() % t; 
            cur.push_back(vector<int>());
                
            //cerr << el << " a ";
            if (sel.find(el) == sel.end()) {
                sel.insert(el);
                //cerr << el << " b  ";

                cur[j].push_back(el);
                //vert
                if (rot[el] == 0) {
                    while (true) {
                        int el2 = rand() % t;   
                        //cerr << el2 << " c "; 
                        if (sel.find(el2) == sel.end() && rot[el2] == 0) {
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
        // TODO
        int count = 0;
        for (int j = 1; j < cur.size(); j ++)
        {
           int r = count(sol[j], sol[j-1]);
           // cout << "new "<< endl;
        }
        if (count > 0 ) {
            sol = cur;
        }
        
        }
    }
        for (int j = 0; j < sol.size(); j ++)
        {
            cout  <<endl; //<< "output"
            fo << endl;
            for (int k = 0 ; k < sol[j].size(); k ++)
            {
                cout << sol[j][k] << " ";
                fo << sol[j][k] << " ";
                //cout<<s[j][0];
            }
           // cout << "new "<< endl;
        }
            fo << endl;
    fo.close();
    
    return 0;
} 
