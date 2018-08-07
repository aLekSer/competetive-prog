#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

typedef __uint128_t ll ;

std::ostream&
operator<<( std::ostream& dest, ll value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        ll tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int algo(const vector<int> & b, int k) {
    // find 0es - set them to 1
    vector<int> c(b.size(), 1000000);
    vector<pair<int, int>> st;
    for (int i = 0; i < b.size(); i++) {
        st.push_back(make_pair(b[i], i));
    }
    int N = b.size();
    sort(st.begin(), st.end());
    for (int i = 0; i < st.size(); i++) {
        cerr << "st" << st[i].first << " " << st[i].second;
        if (st[i].first == 0) {
            c[st[i].second] = 1;
        } else {
            //TODO
            for (int l = 2; l < 100; l ++) {
                c[st[i].second] = l;
                int j = st[i].second;
                int count = 0;
                for (int i = max(0, j-k); i <= min(N-1, j+k); i ++) {
                    if (c[i] < c[j]) {
                        count ++;
                        cerr << "++" ;
                    }
                }
                if (count == b[j]) {
                    break;
                }
            }
            
        }
    }
    
    long long sum_of_elems = 0;
    cerr << "My elems:" << endl;
    for (auto& n : c) {
        cerr << n << " ";
        sum_of_elems += n;
    }
    cerr << endl;
    return sum_of_elems;

}
// gcd (a, b) == gcd( (a^N)% b, b)
int prepare(const vector<int> & a, int s) {
    vector<int> b = a;
    const int n = a.size();
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += a[j];        
    }
    if (sum < s) {
        return n;
    }
    vector<int> c(n, -1);
    int mid = 10000;
    //vector<int>  b (n);
    int k_m;
    for (int k = 1; k < n; k ++) {
            int mi = mid * 2;
            cerr << "K " << k;
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = max(0, j-k); i <= min(n-1, j+k); i ++) {
                if (a[i] < a[j]) {
                    count ++;
                    cerr << "++" ;
                }
            }
            b[j] = count;
            /*
            if (c[j] == -1)
                c[j] = mid;
            for (int i = max(0, j-k); i < j; i ++)
            {
                if (c[i] < c[j]) {
                    count --;
                }
            }
            for (int i = j+1 ; i <  min(n, j+k); i ++) {
                if (i != j) {
                    if (count > 0) {
                        c[i] = c[j] - 1;
                        count --;
                    } else {
                        c[i] = c[j];
                    }
                    if (c[i] < mi) {
                        mi = c[i];
                    }
                }
            }
            */
        }
        auto siz = algo(b, k);
        if (siz <= s) {
            cerr << "Here " <<endl;

        } else {
            //TODO check do we have other K after one fail
            k_m = k;
            break;

        }
        int sum2 = 0;
        for (int j = 0; j < n; j++) {
            cerr << (c[j] - mi + 1 )<< endl;
            sum2 += c[j] - mi + 1;
        }
        cerr << sum2 << endl;
    }
    return k_m;
}
int main() 
{
    int t;
    cin >> t;
    for (int i = 0; i < t ; i++) {
        long long  n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        cout << (long long ) prepare(a, s) << endl;
    }
    return 0;
}

//Some test cases
/*
./mod
1
1999999 1999999 1999994
output: 0 ?


Considerations how we can solve the problem:
    First of all lets solve it on the paper:
        4 2 8 1 4 3 8 1
        Sol for k = 2
        3 2 4 1 3 2 4 1 
        Sol for k = 3
        3 2 4 1 3 2 4 1
        Why we could not do that for k = 4
        4 2 5 1 4 3 5 1 Sum > 20

        Suggested algo:
        start with calculating the number of X the elements < ai
        for example for k = 3:
        2 1 5 0 3 2 4 0

        We could start from 0 to 5
        and then we put 1 for 0,
        2, iterating to valid number for 1
        the same for each other number starting from value = 2 
        
*/

