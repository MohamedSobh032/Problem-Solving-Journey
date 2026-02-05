#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Simulation
     * @details simulates using the given description.
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                int index = (i + nums[i]) % n;
                result[i] = nums[index];
            }
            else if (nums[i] < 0)
            {
                int index = ((i + nums[i]) % n + n) % n;
                result[i] = nums[index];
            }
        }

        return result;
    }

    /**
     * @brief Unified index simulation on a circular array
     * @details difference is the index calculation is unified.
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                int index = ((i + nums[i]) % n + n) % n;
                result[i] = nums[index];
            }
        }

        return result;
    }
};
