nclude <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
typedef long l;
typedef long long ll;
long countTriplets(vector<long> arr, long r) {
    // value to index backward mapping
    unordered_map<l, vector<l>> m;
    for (l i = 0 ; i != arr.size(); i++) {
        m[arr[i]] = vector<l>();
		m[arr[i]].push_back(i);
    }
    int calc = 0;
    set<ll> s;
    vector<vector<l>> d(3,vector<l>());
    vector<l> e(3);
    for (l i = 0 ; i != arr.size(); i++) {
        l x = arr[i] * r;
        bool found = false ;
        d[0] = vector<l>(1, i);
        if (m.find(x) != m.end())
        {
            d[1] = m[x];
            found = true;
        }
        x = x * r;
        if (m.find(x) != m.end())
        {
            d[2] = m[x];
            found = found && true;
        } else {
            found = false;
        }
        if (found) {
            for (int i = 0; i < d[1].size(); i++ ) {
                for (int j = 0; j < d[2].size(); j++ ) {
                    e[0] = d[0][0];
                    e[1] = d[1][i];
                    e[2] = d[2][j];
                    if (e[0] != e[1] && e[2] != e[1] && e[2] != e[0]) 
                    { 
                    	sort(e.begin(), e.end());
                        cerr << e[0] << " " << e[1] << " " << e[2]<<endl;
                        const int b = 1e9;
                        ll num = ll(e[0]) * b * b + ll(e[1]) * b + ll(e[2]);
                        s.insert(num);
                    }
                }
            }
        }
    }
    return s.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


