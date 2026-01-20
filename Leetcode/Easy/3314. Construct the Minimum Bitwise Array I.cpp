#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute Force
     * @details checks all possible j values until (j | (j + 1)) matches the target number.
     * @complexity: Time: O(n * m), Space: O(1)
     */
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nums[i]; j++)
            {
                if ((j | (j + 1)) == nums[i])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }

    /**
     * @brief Precomputation with Hash Map
     * @details precomputes all valid (i | (i + 1)) results and maps them to the smallest i.
     * @complexity: Time: O(n + m), Space: O(m)
     */
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        unordered_map<int, int> cache;
        for (int i = 1000; i >= 0; i--)
        {
            cache[i | (i + 1)] = i;
        }

        for (int &num : nums)
        {
            num = (cache.find(num) == cache.end()) ? -1 : cache[num];
        }
        return nums;
    }
};