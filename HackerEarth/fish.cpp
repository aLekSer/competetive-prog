/*
// Sample code to perform I/O:
 
cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int bin_search(vector<int> & s, int t) {
    int l = 1 ;
    int r = s.size();
    /* TODO
    while(l >= r) {
        if 
    }
    */
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] > t) {
            return i;
        }
    }
    return -1;
}
int run () {
    int n;
    cin >> n;
    vector<int> s(n), e(n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n ; ++i) 
    {
        cin >> s[i] >> e[i];
        p.push_back(make_pair( e[i], s[i]));
    }
    sort(s.begin(), s.end());
    sort(p.begin(), p.end());
    vector<int> c(n);
    for(int i = 0; i < p.size(); i ++)
    {
        int e = p[i].first;
        int l = bin_search(s, e);
        c[i] = i-l+1;
        /*
        if (l >= n - i) {
            return l;
        }
            */
    }
    int max = 1;
    for(int i = 0; i < c.size(); i ++)
    {
        if (c[i] > max)
            max = c[i];
    }
    return max;
}
int main() {
    int t ;
    cin >> t;
    for (int i = 0; i < t ; ++i) 
    {
        cout << run()<< endl;
    }
}