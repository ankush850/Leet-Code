class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";    
        for(int i=1;i<=n;i++){
            s.push_back('0' + i);
        }
        for(int i=0;i<k-1;i++){
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};