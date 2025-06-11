#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Bottom-up DP
     * @details Solves the house robber problem by tracking max money at each step
     *          without robbing two adjacent houses.
     * @complexity: Time: O(n), Space: O(1)
     */
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int n1 = nums[0], n2 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int temp = n2;
            n2 = max(nums[i] + n1, n2);
            n1 = temp;
        }
        return n2;
    }
};
