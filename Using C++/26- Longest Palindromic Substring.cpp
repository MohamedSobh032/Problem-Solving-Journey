/**
 * @brief First Solution
 * -- O(n3)
 * -- Brute-force on all solutions
 */
class Solution {
public:
    bool isPalindrome(const std::string& str) {
        
        int left = 0;
        int right = str.length() - 1;
        while (left < right) {
            if (str[left++] != str[right--])
                return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        
        std::string ret(1, s[0]);
        for (size_t i = 0; i < s.size(); i++) {
            for (size_t j = i + ret.size(); j <= s.size(); j++) {
                std::string substring = s.substr(i, j - i);
                if (isPalindrome(substring) &&  j - i > ret.size())
                    ret = substring;
            }
        }
        return ret;
    }
};

/**
 * @brief Second Solution
 * -- O(n2)
 * -- from inner to outer palindrome search, twice for even and odd case
 */
class Solution {
public:
    string longestPalindrome(string s) {
        
        std::string ret;
        for (size_t i = 0; i < s.size(); i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > ret.size())
                    ret = s.substr(l, r - l + 1);
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > ret.size())
                    ret = s.substr(l, r - l + 1);
                l--;
                r++;
            }
        }
        return ret;
    }
};