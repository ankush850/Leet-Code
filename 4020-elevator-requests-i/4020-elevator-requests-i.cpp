class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int totalTime = 0;
        int currentFloor = 0;
        
        for (int request : requests) {
            totalTime += abs(currentFloor - request);
            currentFloor = request;
        }
        
        return totalTime;
    }
};