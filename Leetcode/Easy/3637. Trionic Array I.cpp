#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Three-Phase Single Pass
     * @details checks whether the array follows a strictly increasing, then strictly decreasing, then strictly increasing pattern using a single forward scan.
     * @complexity: Time: O(n), Space: O(1)
     */
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size(), i = 0;
        if (n == 3)
            return false;
        bool inc1 = false, dec = false, inc2 = false;

        for (; i < n - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
                break;
            else
                inc1 = true;
        }

        for (; i < n - 1; i++)
        {
            if (nums[i] <= nums[i + 1])
                break;
            else
                dec = true;
        }

        for (; i < n - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
                return false;
            else
                inc2 = true;
        }

        return inc1 && dec && inc2;
    }
};
