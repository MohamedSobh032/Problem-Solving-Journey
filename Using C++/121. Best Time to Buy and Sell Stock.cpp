/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Sliding window approach
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buyValue = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (buyValue > prices[i]) buyValue = prices[i];
            else if (prices[i] - buyValue > profit) profit = prices[i] - buyValue;
        }
        return profit;
    }
};