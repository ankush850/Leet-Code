class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int max_light = 0;
        for (int i = 0; i < lights.size(); ++i) {
            if (lights[i] > max_light) {
                max_light = lights[i];
            }
        }
        
        int max_wait = 0;
        for (int i = 0; i < arrivalTime.size(); ++i) {
            int r = arrivalTime[i] % period;
            if (r >= max_light) {
                int wait = period - r;
                if (wait > max_wait) {
                    max_wait = wait;
                }
            }
        }
        
        return max_wait;
    }
};