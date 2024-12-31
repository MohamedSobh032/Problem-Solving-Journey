/**
 * @brief First Solution
 * -- Time Complexity: O(2^n)
 * -- Space Complexity: O(1)
 * -- Recursive solution
 */
class Solution {
public:
    int fib(int n) {

        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Dynamic programming top-down approach
 */
class Solution {
public:
    int rec(int n, std::vector<int>& dp) {

        if (n == 0 || n == 1) return n;
        if (dp[n] != -1) return dp[n];
        dp[n] = rec(n - 1, dp) + rec(n - 2, dp);
        return dp[n];
    }

    int fib(int n) {

        std::vector<int> dp(n + 1, -1);
        return rec(n, dp);
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Dynamic programming bottom-up approach
 */
class Solution {
public:

    int fib(int n) {

        if (n == 0 || n == 1) return n;
        std::vector<int> dp(n + 1, 0);
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

/**
 * @brief Fourth Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Same as above, but using only two variables instead of array
 */
class Solution {
public:
    int fib(int n) {

        if (n == 0 || n == 1) return n;
        int n1 = 0; int n2 = 1;
        for (int i = 2; i <= n; i++) {
            int temp = n2;
            n2 += n1; n1 = temp;
        }
        return n2;
    }
};