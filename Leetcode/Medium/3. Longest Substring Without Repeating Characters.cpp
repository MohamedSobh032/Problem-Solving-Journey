#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute-force with HashSet
     * @details For each starting index, uses a hash set to detect repeating characters and track the longest unique substring
     * @complexity: Time: O(n^2), Space: O(min(n, k)) where k is the character set size
     */
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        int len = s.size();
        int max_len = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            unordered_set<char> set;
            for (int j = i; j < len; j++)
            {
                if (set.count(s[j]) > 0)
                    break;
                set.insert(s[j]);
                max_len = max(max_len, j - i + 1);
            }
        }
        return max_len;
    }

    /**
     * @brief Sliding window with reset on duplicate
     * @details Uses a map to track character indices, resets window on duplicates, not optimal due to repeated scans and clears
     * @complexity: Time: O(n^2) worst case due to full map clears, Space: O(min(n, k))
     */
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return s.size();

        int n = s.size(), start = 0, i = 0, max_len = INT_MIN;
        unordered_map<char, int> nmap;
        while (i < n)
        {
            if (nmap.find(s[i]) != nmap.end())
            {
                i = nmap[s[i]] + 1;
                nmap.clear();
                start = i;
                continue;
            }
            nmap[s[i]] = i;
            max_len = max(max_len, i - start + 1);
            i++;
        }
        return max_len;
    }

    /**
     * @brief Optimized sliding window
     * @details Maintains a window of unique characters using a hash set and expands/shrinks as duplicates are encountered
     * @complexity: Time: O(n), Space: O(min(n, k)) where k is the character set size
     */
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size(), start = 0, max_len = 0;
        unordered_set<char> set;
        for (int i = 0; i < n; i++)
        {
            while (set.find(s[i]) != set.end())
            {
                set.erase(s[start]);
                start++;
            }
            set.insert(s[i]);
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};