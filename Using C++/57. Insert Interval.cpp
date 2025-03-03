/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Iterates over all intervals, if there is an over-lap, changes the newInterval value
 *    else if the newInterval start is greater than the end of the current interval, adds the current interval to the merged vector
 *    else, add the newInterval to the merged vector and then add the rest of the intervals, then returns the merged vector
 */
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {

        int n = intervals.size();
        std::vector<std::vector<int>> merged;
        for (int i = 0; i < n; i++)
        {
            if (newInterval[1] < intervals[i][0])
            {
                merged.emplace_back(newInterval);
                for (int j = i; j < n; j++)
                    merged.emplace_back(intervals[j]);
                return merged;
            }
            else if (newInterval[0] > intervals[i][1])
                merged.emplace_back(intervals[i]);
            else
            {
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        merged.emplace_back(newInterval);
        return merged;
    }
};