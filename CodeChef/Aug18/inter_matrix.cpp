#include <iostream>
#include <vector>

# include <stdio.h>
# include <math.h>
# include <algorithm>

using namespace std;


int main() 
{
    int n, k, v;
    cin >> n >> k >> v;
    bool found = false;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++)
        {
            int cur = 0;
            cout << "1 " << i + 1 << " " << j + 1 << endl;
            cout.flush();
            cin >> cur;
            if (cur == v) {
                found = true;
                cout << "2 " << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    if (!found) {
        cout << "2 -1" << " -1" << endl;
    }
    return 0;
}