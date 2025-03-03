/**
 * @brief First Solution
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(n)
 * -- Sorts the intervals based on the start time, then, iterates through the intervals and merges the overlapping intervals
 */
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        std::vector<std::vector<int>> merged;
        std::sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++)
        {
            int st = intervals[i][0];
            int end = intervals[i][1];
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (intervals[j][0] <= end)
                {
                    st = std::min(st, intervals[j][0]);
                    end = std::max(end, intervals[j][1]);
                    i++;
                    continue;
                }
                break;
            }
            merged.push_back({st, end});
        }
        return merged;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(n)
 * -- Same as above, the difference is that it uses the last element of the merged vector to check
 *    if the current interval overlaps with the last interval, therefore only one iteration needed
 */
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        std::vector<std::vector<int>> merged;
        std::sort(intervals.begin(), intervals.end());
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            int last_start = merged.back()[0];
            int last_end = merged.back()[1];
            if (intervals[i][0] <= last_end)
                merged[merged.size() - 1][1] = std::max(last_end, intervals[i][1]);
            else
                merged.push_back(intervals[i]);
        }
        return merged;
    }
};