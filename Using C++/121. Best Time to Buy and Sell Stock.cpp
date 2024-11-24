/**
 * @brief First/Only Solution
 * -- O(n)
 * -- Sliding window
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {    
        int buyValue = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // if found a new minimum, set it
            if (buyValue > prices[i])
                buyValue = prices[i];
            // if didn't find a new minimum, change the profit if it is any better
            else if (prices[i] - buyValue > profit)
                profit = prices[i] - buyValue;
        }
        return profit;
    }
};