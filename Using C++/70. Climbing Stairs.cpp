/**
 * @brief First Solution
 * -- O(2^n)
 * -- Brute force without dynamic programming
 * -- Worst solution
 */
class Solution {
public:
    void counter(int& solutions, int total, int n) {
        if (total == n) {
            solutions++;
            return;
        } else if (total > n)
            return;
        counter(solutions, total + 1, n);
        counter(solutions, total + 2, n);
    }

    int climbStairs(int n) {
        int solutions = 0;
        counter(solutions, 0, n);
        return solutions;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Brute force with dynamic programming bottom up 
 */
class Solution {
public:
    int climbStairs(int n) {
        // Base case
        if (n == 0 || n == 1)
            return 1;
        // DP vector with initialization = 1 (base case)
        std::vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
