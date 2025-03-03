/**
 * @brief First Solution
 * ---> O(n^2)
 * ---> Bottom up dynamic programming approach
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        std::vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < i + 1 + nums[i]; j++)
            {
                if (j >= nums.size())
                    break;
                if (dp[j])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

/**
 * @brief Second Solution
 * ---> O(n)
 * ---> Bottom up dynamic programming approach
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int destination = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (i + nums[i] >= destination)
                destination = i;
        }
        return destination == 0;
    }
};