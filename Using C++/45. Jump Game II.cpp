/**
 * @brief First Solution
 * ---> O(n^2)
 * ---> Bottom up dynamic programming approach
 */
class Solution
{
public:
    int jump(vector<int> &nums)
    {

        if (nums.size() == 0 || nums.size() == 1)
            return 0;

        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 0;
        dp[nums.size() - 2] = 1;

        for (int i = nums.size() - 3; i >= 0; i--)
        {
            int minimum = INT_MAX;
            for (int j = i + 1; j < i + 1 + nums[i]; j++)
            {
                if (j == nums.size())
                    break;
                minimum = std::min(minimum, dp[j]);
            }
            dp[i] = (minimum == INT_MAX) ? minimum : minimum + 1;
        }
        return dp[0];
    }
};

/**
 * @brief Second Solution
 * ---> O(n)
 * ---> Same as above, only iterating with specific indices
 */
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int near = 0, far = 0, jumps = 0;

        while (far < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = near; i <= far; i++)
                farthest = max(farthest, i + nums[i]);
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;
    }
};