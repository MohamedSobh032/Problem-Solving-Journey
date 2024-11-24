/**
 * @brief First/Only Solution
 * ---> O(n)
 * ---> Get count of all inclusives
 */
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        
        int count = 0;
        for (int i = 0; i < startTime.size(); i++) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                count++;
        }
        return count;
    }
};