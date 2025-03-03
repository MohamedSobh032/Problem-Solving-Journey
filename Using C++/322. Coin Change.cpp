/**
 * @brief First Solution
 * -- m4 3aref agib complexity
 * -- Brute force on all possible solutions
 * -- Gives timeout
 */
class Solution
{
public:
    std::vector<int> solutions;
    void rec(const std::vector<int> &coins, int counts, long long currSum, const int &amount)
    {
        // basecase
        if (currSum > amount)
            return;
        if (currSum == amount)
        {
            solutions.push_back(counts);
            return;
        }

        // recursion
        counts++;
        for (size_t i = 0; i < coins.size(); i++)
            rec(coins, counts, currSum + coins[i], amount);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        rec(coins, 0, 0, amount);
        if (solutions.empty())
            return -1;
        return *std::min_element(solutions.begin(), solutions.end());
    }
};

/**
 * @brief Second Solution
 * -- O(n * amount)
 * -- bottom up dynamic programming solution
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        std::vector<long long> dp(amount + 1, 0);
        for (long long i = 1; i < amount + 1; i++)
        {
            int sol = INT_MAX;
            for (long long j = 0; j < coins.size(); j++)
            {
                if (i < coins[j])
                    continue;
                int curr = dp[i - coins[j]];
                if (curr != -1 && 1 + curr < sol)
                    sol = 1 + curr;
            }
            dp[i] = (sol == INT_MAX) ? -1 : sol;
        }
        return static_cast<int>(dp[amount]);
    }
};

/**
 * @brief Third Solution
 * -- O(n * amount)
 * -- bottom up dynamic programming solution, but less space complexity than the above solution
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        std::vector<long long> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (long long a = 1; a < amount + 1; a++)
        {
            for (const auto &c : coins)
            {
                if (a < c)
                    continue;
                dp[a] = std::min(dp[a], 1 + dp[a - c]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};