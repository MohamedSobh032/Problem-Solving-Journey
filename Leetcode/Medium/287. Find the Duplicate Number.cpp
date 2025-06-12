#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute-force
     * @details checks all pairs to find a duplicate number by comparing every element with all others
     * @complexity: Time: O(n^2), Space: O(1)
     */
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && nums[i] == nums[j])
                    return nums[i];
        return -1;
    }

    /**
     * @brief Floyd’s Tortoise and Hare (Cycle Detection)
     * @details treats values as pointers to next indices and detects a cycle — the duplicate is the entry point
     * @complexity: Time: O(n), Space: O(1)
     */
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};