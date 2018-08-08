#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;

int query(int i , int mid) {

    int cur = 0;
    cout << "1 " << i + 1 << " " << mid + 1 << endl;
    cout.flush();
    cin >> cur;
    return cur;
}

// binary Search on the rows of the matrix
pair<int, int> binS(int n, int v , int i) {
    int l = 0, r = n - 1;
    int cur2 = query(i, r);
    if (cur2 == v) {
        return make_pair(i, r);
    }
    while (l <= r) {
        int mid =  l + (r - l) / 2;
        //cerr << l << " " << r << endl;
        int cur = query(i, mid);
        if (cur == v) {
            return make_pair(i, mid);
        }
        if (cur2  > cur && v > cur2) 
            return make_pair(-1, -1);
        if (cur2  > cur ) {
            if (cur < v) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (cur < v) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    /*
    int mid =  l + (r - l) / 2;
    int cur = query(i, mid);
    if (cur == v) {
        return make_pair(i, mid);
    }
    */
    return make_pair(-1, -1);


}
int main() 
{
    int n, k, v;
    cin >> n >> k >> v;
    bool found = false;


    if (k >= n * n) {
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n; j++)
            {
                int cur = query(i, j);
                if (cur == v) {
                    found = true;
                    cout << "2 " << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    } else {
        for (int i = 0; i < n ; i++) {
            auto res = binS(n, v, i);
            if (res.first != -1) {
                found = true;
                cout << "2 " << res.first + 1 << " " << res.second + 1 << endl;
                cout.flush();
                break;

            }
            /*
            */
        }

    }
    if (!found) {
        cout << "2 -1" << " -1" << endl;
        cout.flush();
    }
    return 0;
}

/* Bug: Examples of infinite loop
3 10 4
1 1 3
8
0 2
1 1 2
6
0 1
1 1 1
2
0 1
1 1 1
2
0 1
1 1 1
2
0 1
1 1 1
2
0 1
1 1 1
*/