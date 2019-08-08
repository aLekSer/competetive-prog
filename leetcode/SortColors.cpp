// 75. Sort Colors


class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }
        int x = 0, y = 0, z = nums.size() - 1;
        for (int i = 0 ; i <  nums.size()  ; i ++) {
            if ( nums[i] == 0 ) {
                swap(nums[i], nums[x]);
                x ++;
            }
            if ( nums[i] == 2 && i < z) {
                swap(nums[i], nums[z]);
                z --;
                i --;
            }
        }
    }
};
