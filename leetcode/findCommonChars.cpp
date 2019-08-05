// 1002. Find Common Characters


class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int t [26];
        for (int i = 0 ; i < 26; i ++) {
            t[i] = INT_MAX; 
        }
        vector<string> ans;
        for (auto s : A) {
            cout << s << endl; 
            int m [26] = {0};
            for (auto c : s) {
                m[ c -'a'] ++;
                //cout << c << endl;
            }
            for (int i = 0 ; i < 26; i ++) {
                    t[i] = min (t[i] , m[i]);
            }
        }
        
        
        for (int i = 0 ; i < 26; i ++) {
            //cout << "First" << e.first << endl;
               //e->second = min (m[e->first] , e->second);
            if (t[i] == INT_MAX)
                 continue;
          //  cout << t[i] << " e " << endl;
            for (int j = 0; j <t[i] ; j ++) {
                string r; 
                r.push_back('a' + i);
                //cout << r;
                ans.push_back(r);
            }
        } 
        return ans;
    }
};
