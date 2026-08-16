class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<int> X = requests;
        X.push_back(start);
        sort(X.begin(), X.end());
        X.erase(unique(X.begin(), X.end()), X.end());
        
        int N = X.size();
        vector<int> is_req(N, 0);
        for (int r : requests) {
            int idx = lower_bound(X.begin(), X.end(), r) - X.begin();
            is_req[idx] = 1;
        }
        
        vector<int> prefix_req(N + 1, 0);
        for (int i = 0; i < N; ++i) {
            prefix_req[i + 1] = prefix_req[i] + is_req[i];
        }
        
        auto cnt = [&](int L, int R) {
            if (L > R) return 0;
            return prefix_req[R + 1] - prefix_req[L];
        };
        
        int S = lower_bound(X.begin(), X.end(), start) - X.begin();
        int R_total = requests.size();
        
        const long long INF = 1e18;
        vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(2, INF)));
        
        dp[S][S][0] = dp[S][S][1] = 0;
        
        for (int len = 2; len <= N; ++len) {
            for (int i = 0; i <= N - len; ++i) {
                int j = i + len - 1;
                
                if (i + 1 <= j) {
                    long long rem = R_total - cnt(i + 1, j);
                    long long d1 = (long long)(X[i + 1] - X[i]) * rem;
                    long long d2 = (long long)(X[j] - X[i]) * rem;
                    
                    if (dp[i + 1][j][0] != INF) 
                        dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][0] + d1);
                    if (dp[i + 1][j][1] != INF) 
                        dp[i][j][0] = min(dp[i][j][0], dp[i + 1][j][1] + d2);
                }
                
                if (i <= j - 1) {
                    long long rem = R_total - cnt(i, j - 1);
                    long long d1 = (long long)(X[j] - X[i]) * rem;
                    long long d2 = (long long)(X[j] - X[j - 1]) * rem;
                    
                    if (dp[i][j - 1][0] != INF) 
                        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + d1);
                    if (dp[i][j - 1][1] != INF) 
                        dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + d2);
                }
            }
        }
        
        return min(dp[0][N - 1][0], dp[0][N - 1][1]);
    }
};