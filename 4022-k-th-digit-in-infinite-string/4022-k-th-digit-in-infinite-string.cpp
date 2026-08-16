class Solution {
    long long power10(int p) {
        long long res = 1;
        for (int i = 0; i < p; ++i) {
            res *= 10;
        }
        return res;
    }

public:
    int kthDigit(long long k) {
        if (k <= 9) return k;
        k -= 9;
        
        long long d = 2;
        while (true) {
            long long num_blocks = 9 * power10(d - 2);
            long long digits_in_this_d = num_blocks * 10 * d;
            
            if (k <= digits_in_this_d) {
                break;
            }
            k -= digits_in_this_d;
            d++;
        }
        
        long long block_offset = (k - 1) / (10 * d);
        long long b = power10(d - 2) + block_offset;
        
        long long rem_k = (k - 1) % (10 * d);
        long long num_idx = rem_k / d;
        long long digit_idx = rem_k % d;
        
        long long val;
        if (b % 2 == 0) {
            val = 10 * b + num_idx;
        } else {
            val = 10 * b + 9 - num_idx;
        }
        
        string s = to_string(val);
        return s[digit_idx] - '0';
    }
};