/**
 * @brief First/Only Solution
 * ---> O(logn)
 * ---> Edited Binary Search
 */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int pivot = (left + right) / 2;
            if (nums[pivot] == target)
                return pivot;
            else if (nums[pivot] >= nums[left])
            {
                if (nums[left] <= target && target <= nums[pivot])
                    right = pivot - 1;
                else
                    left = pivot + 1;
            }
            else
            {
                if (nums[pivot] <= target && target <= nums[right])
                    left = pivot + 1;
                else
                    right = pivot - 1;
            }
        }
        return -1;
    }
};