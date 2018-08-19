#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int N, vector<int> arr) {
    vector<long> c(N, 0);
    int n = arr.size();
    if (n > 2) {
        if( arr[1] > arr[0] ) {
            c[0] = 1;
            c[1] = c[0] + 1;
        } else {
            c[0] = 2;
            c[1] = 1;
        }
    }
    int minIdx = 0;
    /*
    for (int i = 2; i < n ; i++) {
        if (arr[i] > arr[i-1]) {
            c[i] = c[i-1] + 1;
            minIdx = 0;
        } else {
            c[i] =  min(1l, c[i-1]-1);
            cerr << "ci" << c[i] << " " << minIdx;
            if(!minIdx)
                minIdx = i;
            if(c[i] < 1) {
                int tmp = c[i];
                for(int j = i ; j >= minIdx; j--) {
                    cerr << j << "j ";
                    c[j] += (1 - tmp);
                }
            }
        }
    }    */
    c[0] = 1;
    for(int i = 1 ; i < n  ;i++){ //forward track
        if(arr[i] > arr[i-1]){
            c[i] = 1 + c[i-1]; 
        }
        else 
            c[i] = 1;
    }
    for (int i = N-1; i  >= 1; i--) {
        cerr << i << (arr[i-1] > arr[i])<<" : " <<  ( c[i-1] < c[i]);
        if ((arr[i-1] > arr[i] )& ( c[i-1] <= c[i])) {
            c[i-1] = c[i] + 1;
            cerr<< i - 1 << ":" << c[i-1];
        } else {
            cerr << "erlse";
        }
        
    }
    
    long min = 400000;
    long sum = 0;
    for (int i = 0; i < n ; i++) {
        if (c[i] < min) {
            min = c[i];
        }
        sum += c[i];
        cerr << c[i] << " " ;
    }
    cerr << endl;
    long ans = sum ;
     int shift;
    
    if (min < 1) {
        shift = (1-min);
    }
    ans += shift * n;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
 
