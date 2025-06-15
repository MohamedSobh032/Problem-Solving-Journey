#include <vector>
#include <iostream>
using namespace std;

class Solution
{
private:
    bool dfs(const vector<int> &nums, const int &n, int index, vector<int> &canReach)
    {
        if (index < 0 || index >= n)
            return 0;
        if (canReach[index] != -1)
            return canReach[index];

        int flag = 0;
        for (int i = 1; i <= nums[index] && index + i < n; i++)
        {
            flag = dfs(nums, n, index + i, canReach);
            if (flag == 1)
                break;
        }
        return canReach[index] = flag;
    }

public:
    /**
     * @brief DFS with memoization
     * @details initializes the cache and starts the dfs from index 0 to check reachability to the last index
     * @complexity: Time: O(n^2), Space: O(n)
     */
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> canReach(n, -1);
        canReach[n - 1] = 1;
        return dfs(nums, n, 0, canReach);
    }

    /**
     * @brief Greedy
     * @details moves from left to right while tracking the farthest reachable index
     * @complexity: Time: O(n), Space: O(1)
     */
    bool canJump(vector<int> &nums)
    {
        int n = nums.size(), max_reach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > max_reach)
                return false;
            max_reach = max(max_reach, i + nums[i]);
        }
        return true;
    }
};