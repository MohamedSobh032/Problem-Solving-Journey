/**
 * @brief First Solution
 * -- Time Complexity: O(log n)
 * -- Space Complexity: O(1)
 * -- Binary search algorithm
 */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int index = start + (end - start) / 2;
            if (nums[index] == target)
                return index;
            else if (nums[index] < target)
                start = index + 1;
            else
                end = index - 1;
        }
        return -1;
    }
};