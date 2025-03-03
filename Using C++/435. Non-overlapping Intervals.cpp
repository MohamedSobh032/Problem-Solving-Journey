/**
 * @brief First Solutio
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(1)
 * -- Sorts the array, then iterates through the array and checks if the current interval overlaps with the last interval.
 *    if it does, then we increment the counter and update the last_end to the minimum of the two intervals.
 */
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        int last_end = intervals[0][1];
        int counter = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= last_end)
                last_end = intervals[i][1];
            else
            {
                counter++;
                last_end = std::min(last_end, intervals[i][1]);
            }
        }
        return counter;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(1)
 * -- Sorts the array based on the end time of the intervals,
 *    then iterates through the array and checks if the current interval overlaps with the last interval.
 */
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const auto &a, const auto &b)
             {
                 return a[1] < b[1];
             });

        int last_end = intervals[0][1];
        int counter = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= last_end)
                last_end = intervals[i][1];
            else
                counter++;
        }
        return counter;
    }
};