class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const int N = nums.size();

        vector<int> acc(N+1);
        partial_sum(begin(nums), end(nums), begin(acc)+1);

        multiset<int> sums;

        constexpr int HI = numeric_limits<int>::max();
        int ans = HI;
 for (int i = 0; i < nums.size(); ++i) {
            if (i-l+1 >= 0) sums.insert(acc[i-l+1]);
            if (i-r >= 0) sums.erase(sums.find(acc[i-r]));
            const auto it = sums.lower_bound(acc[i+1]);
            if (it != cbegin(sums)) ans = min(ans, acc[i+1] - *prev(it));
        }

        return ans < HI ? ans : -1;
    }
};