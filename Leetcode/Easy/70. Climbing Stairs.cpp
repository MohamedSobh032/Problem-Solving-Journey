#include <vector>
using namespace std;

class Solution
{
private:
    int recursive(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] == -1)
            dp[n] = recursive(n - 1, dp) + recursive(n - 2, dp);
        return dp[n];
    }

public:
    /**
     * @brief Bottom-up iterative DP
     * @details computes for each stair the steps by adding the pervious step and the step before the pervious
     * @complexity: Time: O(n), Space: O(1)
     */
    int climbStairs(int n)
    {
        int n1 = 1, n2 = 1;
        for (int i = 2; i < n + 1; i++)
        {
            int temp = n2;
            n2 += n1;
            n1 = temp;
        }
        return n2;
    }

    /**
     * @brief Top-down recursive DP with memoization
     * @details Same as above only using top-down with memoization
     * @complexity Time: O(n), Space: O(n)
     */
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return recursive(n, dp);
    }
};