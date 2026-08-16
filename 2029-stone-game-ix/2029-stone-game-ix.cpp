class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int z = 0, o = 0, t = 0;
        for(auto &i : stones) {
            if(i % 3 == 0) z++;
            else if(i % 3 == 1) o++;
            else t++;
        }
        if(z & 1) return abs(o - t) >= 3;
        return o && t;
    }
};