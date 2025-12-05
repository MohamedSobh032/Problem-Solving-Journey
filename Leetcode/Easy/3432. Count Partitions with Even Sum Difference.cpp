#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    /**
     * @brief prefix-postfix sums
     * @details maintain two sums while iterating through the array once
     * @complexity: Time: O(n), Space: O(1)
     */
    int countPartitions(vector<int> &nums)
    {
        int left_sum = 0;
        int right_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            left_sum += nums[i];
            right_sum -= nums[i];
            ans += (right_sum - left_sum) % 2 == 0;
        }

        return ans;
    }

    /**
     * @brief math observation,
     * @details if total sum is odd, no valid partitions exist else n-1 valid partitions
     * @complexity: Time: O(n), Space: O(1)
     */
    int countPartitions(vector<int> &nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return sum % 2 == 0 ? nums.size() - 1 : 0;
    }
};
