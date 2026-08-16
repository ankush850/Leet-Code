class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        bool isAllZero = true;
        for (int i = 0; i < n; i++) {

            res ^= nums[i];

            if (nums[i] != 0) {
                isAllZero = false;
            }
        }
        if (isAllZero) {
            return 0;
        }
        if (res != 0) {
            return n;
        }
        return n - 1;
    }
};