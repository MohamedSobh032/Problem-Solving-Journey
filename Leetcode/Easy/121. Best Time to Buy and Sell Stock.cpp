#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Two-Pointer
     * @details compares the prices at the two pointers and updates the left pointer when a lower price is found
     * @complexity: Time: O(n), Space: O(1)
     */
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1, max_profit = 0;
        while (r < prices.size())
        {
            if (prices[l] < prices[r])
                max_profit = max(max_profit, prices[r] - prices[l]);
            else
                l = r;
            r++;
        }
        return max_profit;
    }

    /**
     * @brief Two-Pointer
     * @details keeps track of the minimum price seen so far and calculates the profit at each step
     * @complexity: Time: O(n), Space: O(1)
     */
    int maxProfit(vector<int> &prices)
    {
        int buy_price = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            buy_price = min(buy_price, prices[i]);
            profit = max(profit, prices[i] - buy_price);
        }
        return profit;
    }
};