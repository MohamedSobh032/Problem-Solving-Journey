/**
 * @brief First Solution
 * ---> m4 3aref agib complexity
 * ---> Recursive solution
 */
class Solution {
public:
    void rec(string s, const vector<string>& wordDict, bool& ret) {

        for (int i = 0; i < wordDict.size(); i++) {
            int size = wordDict[i].size();
            std::string target(s.substr(0, size));
            if (target == wordDict[i]) {
                if (s.size() == size) {
                    ret = true;
                    return;
                }
                rec(s.substr(size), wordDict, ret);
            }
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        bool ret = false;
        rec(s, wordDict, ret);
        return ret;
    }
};

/**
 * @brief Second Solution
 * ---> O(wordDictSize * sSize^2)
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        std::vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (i + wordDict[j].size() <= s.size() && s.substr(i, wordDict[j].size()) == wordDict[j])
                    dp[i] = dp[i + wordDict[j].size()];
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }
};