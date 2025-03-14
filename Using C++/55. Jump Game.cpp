/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(n)
 * -- Brute-force approach, for every element, check if it can jump to any true element
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        std::vector<bool> dp(n, false);
        dp[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                if (dp[i + j])
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
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Bottom-up dynamic programming approach
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int destination = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
            if (i + nums[i] >= destination)
                destination = i;
        return destination == 0;
    }
};