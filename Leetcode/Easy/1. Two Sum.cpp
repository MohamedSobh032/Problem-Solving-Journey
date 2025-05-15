#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute-Force
     * @details compares every pair with the target
     * @complexity: Time: O(n^2), Space: O(1)
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size(); j++)
                if (i != j && nums[i] + nums[j] == target)
                    return {i, j};
        return {};
    }

    /**
     * @brief Hashing
     * @details uses a hash map to store the numbers and their indices
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> nmap;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr_target = target - nums[i];
            if (nmap.find(curr_target) != nmap.end())
                return {i, nmap[curr_target]};
            nmap[nums[i]] = i;
        }
        return {};
    }

    /**
     * @brief Sorting + Two-Pointer
     * @details compares the current sum with target and moves the two pointers accordingly
     * @complexity: Time: O(n), Space: O(1)
     * @note Works with sorted array only
     */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
                return {left, right};
            else if (nums[left] + nums[right] > target)
                right--;
            else
                left++;
        }
        return {};
    }
};
