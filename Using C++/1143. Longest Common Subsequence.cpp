/**
 * @brief First Solution
 * ---> m4 3arf agib complexity
 * ---> recursion solution
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        // basecase
        if (text1.size() == 0 || text2.size() == 0)
            return 0;

        // if similiar, add 1 and create a subcall
        if (text1[0] == text2[0])
            return 1 + longestCommonSubsequence(text1.substr(1), text2.substr(1));
        // else get the maximum return of both
        return std::max(longestCommonSubsequence(text1.substr(1), text2),
                         longestCommonSubsequence(text1, text2.substr(1)));
    }
};


/**
 * @brief Second Solution
 * ---> O(nm)
 * ---> Bottom-up dynamic programming approach
 */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; i--) {
            for (int j = text2.size() - 1; j >= 0; j--)
                dp[i][j] = (text1[i] == text2[j]) ? 1 + dp[i + 1][j + 1] : std::max(dp[i + 1][j], dp[i][j + 1]);
        }
        return dp[0][0];
    }
};