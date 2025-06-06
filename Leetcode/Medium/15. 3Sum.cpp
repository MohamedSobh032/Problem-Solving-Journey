#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Two-pointer + Two-Sum
     * @details computes the needed value, then solves the two sum problem with two pointers after sorting them, uses set to remove duplicates
     * @complexity: Time: O(n² log(n)), Space: O(n²)
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ret;
        for (int i = 0; i < n; i++)
        {
            int target = 0 - nums[i];
            int l = 0, r = n - 1;
            while (l < r)
            {
                if (l == i)
                {
                    l++;
                    continue;
                }
                else if (r == i)
                {
                    r--;
                    continue;
                }

                int curr_sum = nums[l] + nums[r];
                if (curr_sum == target)
                {
                    vector<int> inserted = {nums[i], nums[l], nums[r]};
                    sort(inserted.begin(), inserted.end());
                    ret.insert(inserted);
                    r--;
                    l++;
                }
                else if (curr_sum < target)
                    l++;
                else
                    r--;
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }

    /**
     * @brief Two-pointers + Two-sum
     * @details an optimization for the solution above
     *          breaks the iteration before starting the two-sum problem if there is repetition
     *          starts from index i + 1 in the two-sum problem
     *          skips any repeated lefts
     * @complexity: Time: O(n²), Space: O(1) (excluding output)
     */
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int curr_sum = nums[l] + nums[r] + nums[i];
                if (curr_sum == 0)
                {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                }
                else if (curr_sum < 0)
                    l++;
                else
                    r--;
            }
        }
        return ret;
    }
};