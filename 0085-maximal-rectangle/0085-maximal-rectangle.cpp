class Solution {
public:
    int maxRect(vector<int>& mat) {
        int n = mat.size();
        stack<pair<int, int>> st;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().second > mat[i]) {
                int next = i - 1;
                int val = st.top().second;
                st.pop();
                int prev = st.empty() ? -1 : st.top().first;
                maxi = max(maxi, ((next - prev) * val));
            }
            st.push({i, mat[i]});
        }
        while (!st.empty()) {
            int next = n - 1;
            int val = st.top().second;
            st.pop();
            int prev = st.empty() ? -1 : st.top().first;
            maxi = max(maxi, ((next - prev) * val));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> histMat(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            histMat[0][i] = matrix[0][i] - '0';
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    histMat[i][j] = 0;
                    continue;
                }
                histMat[i][j] = histMat[i - 1][j] + (matrix[i][j] - '0');
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int val = maxRect(histMat[i]);
            maxi = max(maxi, val);
        }
        return maxi;
    }
};