/**
 * @brief First Solution
 * ---> O(n * m)
 * ---> Bottom up dynamic programming approach
 */
class Solution
{
public:
    // bottom up solution
    int uniquePaths(int m, int n)
    {

        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

        for (int i = 0; i < n - 1; i++)
            dp[m - 1][i] = 1;

        for (int i = 0; i < m - 1; i++)
            dp[i][n - 1] = 1;

        for (int i = m - 2; i >= 0; i--)
            for (int j = n - 2; j >= 0; j--)
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];

        return dp[0][0];
    }
};