#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @details sort both strings then compare them
     * @complexity: Time: O(n log(n)), Space: O(1)
     */
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    /**
     * @details Compares the frequencies of characters in both arrays by subtraction
     * @complexity: Time: O(n), Space: O(1)
     */
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int freqs[26] = {0};
        for (const char &c : s)
            freqs[c - 'a']++;

        for (const char &c : t)
            freqs[c - 'a']--;

        for (const int &num : freqs)
            if (num != 0)
                return false;

        return true;
    }
};