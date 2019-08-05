// Author: aLekSer
// 914. X of a Kind in a Deck of Cards

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for ( auto i : deck) {
            m[i] ++;
        }
        int i = m.begin()->second;
        for (auto p : m) {
            if (p.second >  i ) {
                i = p.second;
            }
        }
        
        bool  br = false;
        for (int j = 2; j <=i ; j ++)
        {
            for (auto p : m) {
                if (p.second % j != 0) {
                    br = true;
                    break;
                }
            }
            if (!br) {
                return true;
            } else 
                br = false;
        }
        return false;
    }
};