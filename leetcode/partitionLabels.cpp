// 763. Partition Labels
/*
Medium
Favorite
Share
A string S of lowercase letters is given. We want to partition this string
 into as many parts as possible so that each letter appears in at most one
  part, and return a list of integers representing the size of these parts.
 */



class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> mi, ma;
        
        vector<int > ans;
        int i = 0;
        for (auto c : S) {
            /* No need in start places
            if (mi.find(c) == mi.end()) {
                mi[c] = i;
            }
            */
            ma[c] = i;
            i++;
        }
        int cur =0;
        int start = 0;
        for ( int i = 0 ; i < S.length() ; i ++) {
            if ( i > cur + start ) {
                start = i;
                ans.push_back(cur + 1);
                cur = 0;
            }
            cur  = max ( ma[S[i]] - start, cur ) ;
        } 
            ans.push_back(cur + 1);
        
        /* An example of how to solve 
           My Calendar III task
        map<int, int> m;
        for (auto k : mi) {
            m[k.second] ++;
            m[ma[k.first]] --;
        }
        // Then iterate over the m and calculate 
         the number of started meetings/ events 
        */
        return ans;
    }
};