class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();
        
        vector<int> first_valid(n);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < m && station[j] != skill[i]) {
                j++;
            }
            first_valid[i] = j;
            j++;
        }
        
        vector<int> last_valid(n);
        j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            while (j >= 0 && station[j] != skill[i]) {
                j--;
            }
            last_valid[i] = j;
            j--;
        }
        
        int max_gap = 0;
        for (int i = 1; i < n; ++i) {
            int gap = last_valid[i] - first_valid[i - 1];
            if (gap > max_gap) {
                max_gap = gap;
            }
        }
        
        return max_gap;
    }
};