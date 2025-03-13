/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Uses an index to save the current write location, this index is updated when the element is not 0, if 0, the write index remains in place for any element to change with
 */
class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int write = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && nums[i] == nums[i + 1] && nums[i] != 0)
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }

            if (nums[i] != 0)
            {
                if (i != write)
                    std::swap(nums[i], nums[write]);
                write++;
            }
        }
        return nums;
    }
};