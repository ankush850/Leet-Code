class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        ranges::sort(meetings, {}, [](auto& m) { return m[1]; });

        vector<long long> ends{-1}, best{LLONG_MIN / 2};
        long long ans = 0;
        for (auto& m : meetings) {
            long long s = m[0], e = m[1], r = m[2];
            long long prev = s + best[upper_bound(ends.begin(), ends.end(), s) - ends.begin() - 1];
            if (prev > 0) r += prev;
            ans = max(ans, r);
            if (r - e > best.back()) { 
                ends.push_back(e);
                best.push_back(r - e);
            }
        }
        return ans;
    }
};