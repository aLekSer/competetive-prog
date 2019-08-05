// 697 Degree of an Array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i : nums) {
            m[i] ++;
        }
        int ma = 0;
        for (auto e: m) {
            ma = max(ma, e.second);
        }
        int t = INT_MAX;
        for (auto e: m) {
            int l = -1;
            if (ma ==  e.second) {
                int c = 0;
                for (auto i : nums) {
                    if (i == e.first && l == -1) {
                        l = 0 ; c ++; 
                        continue;
                    }
                    if (l != -1 && c != ma ) {
                        if (i == e.first) 
                            c ++;
                        l ++;
                        //cout << i << endl;
                    }
                }
            }
            if (l != -1)
                t = min(t, l + 1);
        }
        return t;
    }
};

// Much better solution O(N)

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int > right;
        unordered_map<int, int > count;
        for (int  i = 0 ; i < nums.size(); i ++ ) {
            if(left.find(nums[i]) == left.end())
                left[nums[i]]  = i;
            right[nums[i]] = i;
            count[nums[i]] ++;
        }
        int deg = 0;
        for (auto e : count) {
            deg = max(deg, e.second);
        }
        int ans = nums.size();
        for (auto e: count) {
            if (e.second == deg)
                ans = min(ans, right[e.first] - left[e.first] + 1);
        }
        return ans;
    }
};
