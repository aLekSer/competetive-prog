#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Trie {
    public:
    Trie() {
        for (int i = 0 ; i < 26; i ++) {
            c[i] = NULL;
        }
    }
    Trie * c [26];
    int v ;
};

class Solution {
    Trie t;
    void pushTrie(string s) {
        Trie* a = &t;
        for (char c : s ) {
            if (a->c[c-'a'] == NULL) {
                Trie* n = new Trie;
                a->c[c-'a'] = n;

            }
                a =  a->c[c-'a'];
        }
        a->v = 1;
    }
    vector<string> getWords(string s) {
        Trie* a = &t;
        string l;
        vector<string> v;
        for (char c : s ) {
            Trie * pr = a;
            a = a->c[c-'a'];
            l += c;
            if (a == NULL)  {
                break;
            }
            if (a->v == 1) {
                v.push_back(l);
            }
        }
        return v;
    }
public:
    bool find(string s) {
        if (s.size() == 0 )
            return true;
       auto v = getWords(s);
        if (v.size() == 0)
            return false;
        std::cout<< v[0] << endl;
        for (string l: v) {
            auto t = s.substr(l.length(), s.length() - l.length());
            cout << t <<endl;
            if (find(t))
                return true;
        }
        return false;
    }
     bool wordBreak(string s, vector<string>& wordDict) {
        for (string word: wordDict) {
            pushTrie(word);
        }
        return find(s);
    }
};

int main( ) {
    /*
    "catsandog"
["cats","dog","sand","and","cat"]
 */
    vector<string> l {"bbb","b"};
    Solution s;
   bool b =   (s.wordBreak("bb", l) );
   cout << (b ? "tr" : "f");
}