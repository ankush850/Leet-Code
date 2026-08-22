class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for (int x : candyType) {
            st.insert(x);
        }
        return min((int)candyType.size() / 2, (int)st.size());
    }
};