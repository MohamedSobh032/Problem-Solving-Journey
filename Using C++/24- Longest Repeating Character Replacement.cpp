/**
 * @brief First Solution
 * -- O(n)
 * -- basic sliding window
 */
class Solution {
public:

    int getTopFreq(const std::unordered_map<char, int>& nmap) {
        
        int ret = INT_MIN;
        for (const auto& pair: nmap)
            ret = std::max(ret, pair.second);
        return ret;
    }

    int characterReplacement(string s, int k) {

        std::unordered_map<char, int> nmap;
        int l = 0;
        int maximum = INT_MIN;
        for (int r = 0; r < static_cast<int>(s.size()); r++) {
            nmap[s[r]]++;
            while (r - l + 1 - getTopFreq(nmap) > k) {
                nmap[s[l]]--;
                l++;
            }
            maximum = std::max(maximum, r - l + 1);
        }
        return maximum;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Same as above, only difference is that I have the top frequency in each iteration
 */
class Solution {
public:
    int characterReplacement(string s, int k) {

        std::unordered_map<char, int> nmap;
        int l = 0;
        int maximum = INT_MIN;
        int maxf = 0;
        for (int r = 0; r < static_cast<int>(s.size()); r++) {
            nmap[s[r]]++;
            maxf = std::max(maxf, nmap[s[r]]);
            while (r - l + 1 - maxf > k) {
                nmap[s[l]]--;
                l++;
            }
            maximum = std::max(maximum, r - l + 1);
        }
        return maximum;
    }
};