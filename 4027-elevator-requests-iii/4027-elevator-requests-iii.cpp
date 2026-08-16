class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();
        if (m == 0) return 0;
        
        vector<vector<long long>> dp(1 << m, vector<long long>(m, -1));
        
        for (int i = 0; i < m; ++i) {
            long long dist = abs(start - requests[i][1]);
            long long arrival = requests[i][0];
            dp[1 << i][i] = max(arrival, dist);
        }
        
        for (int mask = 1; mask < (1 << m); ++mask) {
            for (int i = 0; i < m; ++i) {
                if (!(mask & (1 << i)) || dp[mask][i] == -1) continue;
                
                for (int j = 0; j < m; ++j) {
                    if (mask & (1 << j)) continue;
                    
                    long long dist = abs(requests[i][1] - requests[j][1]);
                    long long arrival = requests[j][0];
                    long long next_time = max(arrival, dp[mask][i] + dist);
                    
                    int next_mask = mask | (1 << j);
                    if (dp[next_mask][j] == -1 || next_time < dp[next_mask][j]) {
                        dp[next_mask][j] = next_time;
                    }
                }
            }
        }
        
        long long ans = -1;
        int full_mask = (1 << m) - 1;
        for (int i = 0; i < m; ++i) {
            if (dp[full_mask][i] != -1) {
                if (ans == -1 || dp[full_mask][i] < ans) {
                    ans = dp[full_mask][i];
                }
            }
        }
        
        return ans;
    }
};