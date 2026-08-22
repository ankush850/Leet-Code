class Solution {
public:
    long long possiblecount(vector<int>& coins,long long x){
        int m = coins.size();
        int num = 1<<m ;
        long long  count = 0 ;
   for (int subset = 1; subset < num; subset++) {
           long long lcm = 1;
            int selected = 0;
            bool valid = true;
     for (int i = 0; i < m; i++) {
     if (subset & (1 << i)) {
         selected++;
         long long g = gcd(lcm, (long long)coins[i]);
         lcm = (lcm / g) * coins[i];
          if (lcm > x) {
                 valid = false;
                 break;
                    }
                }
            }
         if (!valid)
            continue;
      long long multiples = x / lcm;
   if (selected % 2 == 1)
                count += multiples;
            else
                count -= multiples;
        }
            return count;
    }
 
    long long findKthSmallest(vector<int>& coins, int k) {
     
     long long start = 1 , end = 1e11 , ans = 0 ;
      while(start<end){
          long long mid = start+(end-start)/2 ;
          long long count = 0 ;
          count = possiblecount(coins , mid);
          if(count<k){
            start = mid+1;
          }
          else{
           end = mid;
          }
      }
      return start ;
    }
};