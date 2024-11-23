/**
 * @brief First/Only Solution
 * -- O(n2)
 * -- Same as Longest Palindromic Substring, but count instead of getting maximum
 */
class Solution {
public:
    int countSubstrings(string s) {

        int ret = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                ret++;
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                ret++;
                l--;
                r++;
            }
        }
        return ret;
    }
};