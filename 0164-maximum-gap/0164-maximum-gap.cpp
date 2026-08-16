class Solution {
public:
    int maximumGap(vector<int>& nums) {
        set<int> s;
        for(auto x:nums)
        s.insert(x);
        int ans=INT_MIN,prev=INT_MIN;
        for(auto x:s)
        {
            if(prev==INT_MIN)
            {
                prev=x;
                continue;
            }
            else
            {
                ans=max(ans,x-prev);
                prev=x;
            }
        }
        return ans==INT_MIN?0:ans;
    }
};