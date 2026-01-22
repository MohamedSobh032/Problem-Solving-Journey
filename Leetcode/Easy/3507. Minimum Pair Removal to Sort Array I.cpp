#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    /**
     * @brief Greedy Simulation (Minimum Adjacent Sum Merge)
     * @details repeatedly merges the adjacent pair with the smallest sum until the array becomes sorted.
     * @complexity: Time: O(n^2 log n), Space: O(1)
     */
    int minimumPairRemoval(vector<int> &nums)
    {
        int num_of_ops = 0, n = nums.size();
        while (!std::is_sorted(nums.begin(), nums.end()))
        {
            int index = -1, minimum_sum = INT_MAX;
            for (int i = 1; i < nums.size(); i++)
            {
                int curr_sum = nums[i] + nums[i - 1];
                if (curr_sum < minimum_sum)
                {
                    index = i;
                    minimum_sum = curr_sum;
                }
            }
            nums[index] = minimum_sum;
            nums.erase(nums.begin() + index - 1);
            num_of_ops++;
        }

        return num_of_ops;
    }

    /**
     * @brief Greedy Simulation with Early Exit
     * @details merges the minimum-sum adjacent pair while the array is not in non-decreasing order.
     * @complexity: Time: O(n^2), Space: O(1)
     */
    int minimumPairRemoval(vector<int> &nums)
    {
        int num_of_ops = 0;
        while (nums.size() > 1)
        {
            bool asc = true;
            int index = -1, minimum_sum = INT_MAX;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                int current_sum = nums[i] + nums[i + 1];
                if (nums[i] > nums[i + 1])
                    asc = false;

                if (current_sum < minimum_sum)
                {
                    index = i;
                    minimum_sum = current_sum;
                }
            }

            if (asc)
                break;

            nums[index] = minimum_sum;
            nums.erase(nums.begin() + index + 1);
            num_of_ops++;
        }

        return num_of_ops;
    }
};
