ass Solution {
    int mi ;
    unordered_set<string> ans;
    void reset () {
                        ans = unordered_set<string>();
        mi = INT_MAX;
    }
    void remain(string s, int id, int l, int r, string expr, int rem) {
        if (id == s.length()) {
            if (l == r) {
                if (rem <= mi ) {
                    if ( rem < mi ) {
                        ans = unordered_set<string>();
                        mi = rem;
                //cout << expr << endl << id << s.length() << rem;
                    }
                    ans.insert(expr);
                }
            }
        } else {
            char c = s[id];
            if ( c != '(' && c != ')') {
                expr += c;
                remain(s, id + 1, l, r, expr, rem);
            } else {
                remain(s, id + 1 , l , r , expr, rem + 1);
                expr += c;
                if (s[id] == '(' ) {
                    remain(s, id + 1, l+1, r, expr, rem);
                } else if (r < l) {
                    remain(s, id + 1, l, r+1, expr, rem);
                }
            }
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        reset();
        string t;
        for (int i = s.length() - 1; i >=0; i --) {
            if (s[i] == '(') {
            } else {
                t = s.substr(0, i+1);
                break;
            }
        }
        cout << t;
        remain(t, 0,0,0, "",0);
        vector<string> res ;
        for (string s : ans) {
            res.push_back(s);
        }
        return res;
    }
};

