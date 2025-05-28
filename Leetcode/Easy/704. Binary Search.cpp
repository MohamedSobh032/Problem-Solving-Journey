#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Binary Search
     * @details custom binary search implementation to find the target in a sorted array.
     * @complexity: Time: O(log(n)), Space: O(1)
     */
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int center = (l + r) / 2;
            if (nums[center] == target)
                return center;
            else if (nums[center] < target)
                l = center + 1;
            else
                r = center - 1;
        }
        return -1;
    }
};