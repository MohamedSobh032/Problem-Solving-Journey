#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Bottom-up iterative DP
     * @details each stair has the minimum cost to get their, and for each stair you compute the minimum of the pervious stairs + their costs
     * @complexity: Time: O(n), Space: O(n)
     */
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        for (int i = 2; i < n + 1; i++)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        return dp[n];
    }
};