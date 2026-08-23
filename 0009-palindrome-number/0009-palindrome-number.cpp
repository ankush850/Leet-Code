class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return 0;
        }
        
        long long rev = 0; 
        int y = x, rem = 0;
        
        while(x > 0){
            rem = x % 10;
            rev = (rev * 10) + rem;
            x = x / 10;
        }
        
        return y == rev;
    }
};