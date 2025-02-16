class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        minimum = prices[0]
        profit = 0
        for price in prices[1:]:
            if price < minimum:
                minimum = price
            elif price - minimum > profit:
                profit = price - minimum
        return profit