/**
 * @brief First/Only Solution
 * ---> O(n)
 * ---> dynamic programming bottom up approach, iterative
 */
class Solution {
public:
    int numDecodings(string s) {

        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            dp[i] = (s[i] == '0') ? 0 : dp[i + 1];
            if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'))
                dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};