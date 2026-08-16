class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int min_ops = 2e9;
        
        for (int k = 0; k < n; ++k) {
            int ops = k;
            for (int i = 0; i < n / 2; ++i) {
                int left = (i + k) % n;
                int right = (n - 1 - i + k) % n;
                int diff = abs(s[left] - s[right]);
                ops += min(diff, 26 - diff);
            }
            if (ops < min_ops) {
                min_ops = ops;
            }
        }
        
        return min_ops;
    }
};