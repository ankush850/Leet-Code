class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr1);
        ranges::sort(arr2);
        arr2.push_back(INT_MAX); 
        int count = 0;
        auto b = arr2.begin();
        for (int a : arr1) {  
            while (*b < a - d) ++b;
            count += *b > a + d;
        }
        return count;
    }
};