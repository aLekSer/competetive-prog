#include <iostream>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int T;
    	cin >> T;
	vector<string> s;
	for (int i = 0 ; i < T; i++)
	{
	    string n;
	    cin >> n;
	    s.push_back(n);
	}
	int Q;
	cin >> Q;
	for (int i = 0 ; i < Q; i++)
	{
	    int R;
	    string P;
	    cin >> R;
	    vector<string> res;
        cin >> P;
	    int longest = 0;
	    for (int j = 0; j < R; j++){
	        int m = max(P.length(), s[j].length());
	        int total = 0;
	        for (int l = 0; l < m; l ++  )
	        {
	            if (P[l] == s[j][l]){
	                total ++;
	            } else {
	                break;
	            }
	            
	        }
	        if (total > longest) {
	            res = vector<string>(0);
	            res.push_back(s[j]);
	            //cout << res[0];
                total = longest;
	        } else {
	            res.push_back(s[j]);

            }
	    }
        string min = "}";
	    for (int j = 0; j < res.size(); j++){
	        if (res[j] < min ||  res[j].length() < s[j].length()) {
	            min = res[j];
	        }
	    }
	    cout << min << endl;
	}
	return 0;
}
