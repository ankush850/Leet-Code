class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::stack<int> stack;
        stack.push(0);
        std::vector<int> r(temperatures.size(), 0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                int index = stack.top();
                stack.pop();
                r[index] = i - index;
            }
            stack.push(i);
        }
        return r;
    }
};