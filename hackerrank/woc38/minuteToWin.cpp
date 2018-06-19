#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minuteToWinIt function below.
int minuteToWinIt(vector<int> a, int k) {
    // Return the minimum amount of time in minutes.
    
    /*
    set<int> s;
    for (int i = 0; i < a.size(); i ++) {
        s.insert(a[i]);
    }
    */
    set<int> s;
    int min_count = 100000;
    vector<int> ss(k+1, 0);
    vector<vector<pair<int, int>>> v(k+1, vector<pair<int, int>>());
    for (int i = 0; i < a.size(); i ++) {
        ss[a[i] % k] ++;
        v[a[i] % k].push_back(make_pair(i, a[i]));
    }
    for (int i = 0; i < a.size(); i++) {
        set<int>::iterator it = s.find(i);
        if ((a.size()-ss[a[i]% k]) > min_count)
            continue;
    int count = a.size()-ss[a[i]% k];
        //cerr << "sfd " << endl;
        if (it == s.end())
        {
            for (int j = 0; j < v[a[i] % k].size(); j ++) {
                //cerr << " f " << v[a[i] % k][j].second;
                //cerr << " s " << a[i] + (v[a[i] % k][j].first - i)*k;
                if(i != v[a[i] % k][j].first && v[a[i] % k][j].second != a[i] + (v[a[i] % k][j].first - i)*k) {
                    count ++;
                    
                    // cerr << v[a[i] % k][j].first <<  " "<< v[a[i] % k][j].second << endl;
                    if (count > min_count) {
                        break;
                    }
                } else if (i != v[a[i] % k][j].first ) {
                    s.insert(v[a[i] % k][j].first );
                }
            }
            if (count < min_count) {
                min_count = count;
            }
        }
    }
    return min_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minuteToWinIt(a, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

