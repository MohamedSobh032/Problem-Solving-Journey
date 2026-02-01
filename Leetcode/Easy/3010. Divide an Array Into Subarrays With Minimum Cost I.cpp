#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute Force
     * @details tries all possible pairs (i, j) with the first element fixed.
     * @complexity: Time: O(n^2), Space: O(1)
     */
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 3)
            return nums[0] + nums[1] + nums[2];

        int min_sum = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i != j)
                {
                    min_sum = std::min(min_sum, nums[0] + nums[i] + nums[j]);
                }
            }
        }

        return min_sum;
    }

    /**
     * @brief Sorting-Based Selection
     * @details sorts all elements except the first and picks the two smallest values.
     * @complexity: Time: O(n log n), Space: O(1)
     */
    int minimumCost(vector<int> &nums)
    {
        int n = nums.size();
        std::sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }

    /**
     * @brief Single Pass
     * @details scans once to find the two smallest values.
     * @complexity: Time: O(n), Space: O(1)
     */
    int minimumCost(vector<int> &nums)
    {
        int fst_min = std::min(nums[1], nums[2]);
        int snd_min = std::max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); i++)
        {
            if (nums[i] < fst_min)
            {
                snd_min = fst_min;
                fst_min = nums[i];
            }
            else if (nums[i] < snd_min)
            {
                snd_min = nums[i];
            }
        }

        return nums[0] + fst_min + snd_min;
    }
};
