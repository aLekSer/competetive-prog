#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>
# include <list>
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
const int K = 271;
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
    return 0;
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
    cout << t << endl;


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
    int m = 10 ;

    // Best solution
    int total = 0;
    int sum = 0;
    list<vector <int> > sol;

    /*
    for (int j = 0; j < t; j ++)
    {
        cout << "ou" << rot[j] <<endl;
    }
    */
   int T = t-1;
   switch (t) {
       case 1000:
       T = t/3;

   }
    for (int i = 0; i < m; i ++) {
        vector<vector <int> > cur;
        list<vector <int> > curl;
        set<int> sel ; 
        for (int j = 0; j < T; j ++) {
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

        for (int j = 0; j < T; j ++) {
            curl.push_back(cur[j]);
        }
        // TODO
        int coun = 0;
        set<int> select;
        list<vector<int>>::iterator it = curl.begin();
        int j = 0;

        list<vector<int>>::iterator it2 = curl.begin();
        int j2 = 0;
        for (; ++it2 != curl.end();)
        {
           int r = count(*it, *it2);
           // cout << "new "<< endl;
            if (r > 0 ) {
                coun += r;
                select.insert(j);
                select.insert(j2);
                ++ it;
            } else {
                coun = 0;
            }
            }
            if (coun != 0 && coun > sum) {
                sum = coun;
                sol = cur;
            }
        
        }
    }
    fo << sol.size() << endl;
        for (int j = 0; j < sol.size(); j ++)
        {
            cout  <<endl; //<< "output"
            for (int k = 0 ; k < sol[j].size(); k ++)
            {
                cout << sol[j][k] << " ";
                fo << sol[j][k] << " ";
                //cout<<s[j][0];
            }
            fo << endl;
           // cout << "new "<< endl;
        }
           // fo << endl;
    fo.close();
    
    return 0;
} 
