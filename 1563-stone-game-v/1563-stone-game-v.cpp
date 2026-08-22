class Solution {
public:
  int dfs( int i , int j , vector<vector<int>> & dp , vector<int> & pre){
        if( i == j ){
            return 0 ;
        }
        int ans = 0 ;
        if( dp[i][j] != -1) return dp[i][j] ;
        for( int k = i  ; k<j ; k++){
            int s1 = pre[k + 1] - pre[i];  
            int s2 = pre[j + 1] - pre[k + 1]; 
            if( s1 > s2 ) ans = max( ans , s2 + dfs( k+1 , j , dp , pre)) ;
            else if( s2 > s1 ) ans = max( ans , s1 + dfs( i , k , dp , pre));
            else ans = max( ans , s1 + max( dfs( i , k , dp , pre) , dfs( k+1 , j , dp , pre ) )) ;
        }
        return dp[i][j] = ans ;
    }
    int stoneGameV(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>> dp(n + 1 , vector<int> ( n + 1 , -1)) ;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];
        return dfs( 0 , n-1 , dp , pre ) ;
    }
};
