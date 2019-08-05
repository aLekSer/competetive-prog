// Author: aLekSer
// 914. X of a Kind in a Deck of Cards

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for ( auto i : deck) {
            m[i] ++;
        }
        int g = -1;
        for (auto p : m) {
                
            if (p.second > 0) {
                if (g == -1)
                    g = p.second;
                else
                    g = gcd(g, p.second);
            }
        }
        return g>= 2;
    }
    
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y%x, x);
    }
};