#include <vector>
#include <climits>
using namespace std;

class Solution
{
private:
    int dfs(int value, vector<int> &dp, const vector<int> &coins)
    {
        if (value < 0)
            return INT_MAX;
        if (value == 0)
            return 0;
        if (dp[value] != 0)
            return dp[value];

        int minimum = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
            minimum = min(minimum, dfs(value - coins[i], dp, coins));
        dp[value] = minimum == INT_MAX ? INT_MAX : minimum + 1;
        return dp[value];
    }

public:
    /**
     * @brief Bottom-up DP
     * @details builds the solution iteratively using previous states
     * @complexity: Time: O(amount * n), Space: O(amount)
     */
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);
        for (int coin : coins)
            if (coin <= amount)
                dp[coin] = 1;

        for (int i = 1; i < amount + 1; i++)
        {
            int minimum = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] > i)
                    continue;
                minimum = std::min(minimum, dp[i - coins[j]]);
            }
            dp[i] = minimum == INT_MAX ? INT_MAX : minimum + 1;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

    /**
     * @brief Top-down DP
     * @details solves recursively with memoization
     * @complexity: Time: O(amount * n), Space: O(amount) (recursive stack)
     */
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);
        int ret = dfs(amount, dp, coins);
        return ret == INT_MAX ? -1 : ret;
    }
};