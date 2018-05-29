#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


const string NG = "no groups";
// Complete the membersInTheLargestGroups function below.
void membersInTheLargestGroups(int n, int m, int a, int b, int f, int s, int t) {
    // Print the names of the students in all largest groups or determine if there are no valid groups.
    string s1;
    int gr;
    vector<vector<int>> v;
  std::unordered_map<std::string, int> name;
    for (int i ; i < n; i++ )
    {
        cin >> s1 >> gr;
        name[s1] = gr; 
    }
    vector<set<string> > my_sets;
    string a1, b1;
    for (int i ; i < m; i++ )
    {
        cin >> a1 >> b1;
        //name[s1] = gr; 
        bool placed = false;
        bool found = false;
        for (int j = 0; j < my_sets.size(); j++)
        {
            set<string>::iterator it = my_sets[j].find(a1);
            if (it != my_sets[j].end())
            {
            set<string>::iterator it3 = my_sets[j].find(b1);
            if (it3 != my_sets[j].end())
            {
                if (v[j][1] <= f &&
                    v[j][2] <= s &&
                     v[j][3] <= t && 
                         my_sets[j].size() < b)
                {
                my_sets[j].insert(b1);
                placed = true;
                
                cerr << a1 << b1;
            v[j][name[b1]] ++;
                    v[j][0] += 1;
                break;
                } else {
                    placed = true;
                     set<string> s2;
        s2.insert(b1);
            v.push_back(vector<int>(4));
            v[v.size()-1][name[b1]] ++;
            my_sets.push_back(s2);
                    v[v.size()-1][0] += 1;
                    break;
                    
                }
                }
            }
            set<string>::iterator it2 = my_sets[j].find(b1);
            if (it2 != my_sets[j].end())
            {
            set<string>::iterator it3 = my_sets[j].find(a1);
            if (it3 != my_sets[j].end())
            {
                if (v[j][1] <= f &&
                    v[j][2] <= s &&
                     v[j][3] <= t && 
                         my_sets[j].size() < b)
                {
                     my_sets[j].insert(a1);
                    placed = true;
                v[j][name[a1]] ++;
                    v[j][0] += 1;
                    break;
                    } else {
                    placed = true;
                     set<string> s2;
        s2.insert(a1);
            v.push_back(vector<int>(4));
            v[v.size()-1][name[a1]] ++;
            my_sets.push_back(s2);
                    v[v.size()-1][0] += 1;
                    break;
                    
                }
            }
            }
        }
        if (!placed) {
            set<string> s2;
        s2.insert(a1);
        s2.insert(b1);
            v.push_back(vector<int>(4));
            v[v.size()-1][name[a1]] ++;
            v[v.size()-1][name[b1]] ++;

                    v[v.size()-1][0] += 2;
            my_sets.push_back(s2);
            
        }
    }
    int max = a;
        for (int j = 0; j < my_sets.size(); j++)
        {
            if (my_sets[j].size() < a)
            {
                cout << NG;
                return;
            }
            if (my_sets[j].size() > max) {
                max = v[j][0];
            }
            
        }
    
        for (int j = 0; j < my_sets.size(); j++)
        {
            if(my_sets[j].size() == max)
            {
                for (set<string>::iterator it = my_sets[j].begin();
                    it != my_sets[j].end(); ++it )
                {
                    cout << *it << endl;
                }
            }
        }
}

int main()
{
    string nmabfst_temp;
    getline(cin, nmabfst_temp);

    vector<string> nmabfst = split_string(nmabfst_temp);

    int n = stoi(nmabfst[0]);

    int m = stoi(nmabfst[1]);

    int a = stoi(nmabfst[2]);

    int b = stoi(nmabfst[3]);

    int f = stoi(nmabfst[4]);

    int s = stoi(nmabfst[5]);

    int t = stoi(nmabfst[6]);

    membersInTheLargestGroups(n, m, a, b, f, s, t);

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

