#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    /**
     * @brief Sort-based approach
     * @details Sorts the array, finds the first gap between consecutive elements
     * @complexity: Time: O(n log n), Space: O(1)
     */
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1] + 1)
                return nums[i] - 1;
        return nums.size();
    }

    /**
     * @brief Linear difference sum approach
     * @details Iteratively accumulates difference between index and value, initialized with n
     * @complexity: Time: O(n), Space: O(1)
     */
    int missingNumber(vector<int> &nums)
    {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++)
            res += i - nums[i];
        return res;
    }

    /**
     * @brief Gauss formula approach
     * @details Computes expected sum using formula and subtracts actual sum
     * @complexity: Time: O(n), Space: O(1)
     */
    int missingNumber(vector<int> &nums)
    {
        int actual_sum = accumulate(nums.begin(), nums.end(), 0);
        int expected_sum = nums.size() * (nums.size() + 1) / 2;
        return abs(actual_sum - expected_sum);
    }
};