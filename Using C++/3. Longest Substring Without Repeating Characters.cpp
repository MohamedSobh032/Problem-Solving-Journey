/**
 * @brief First Solution
 * -- m4 3aref agib complexity
 * -- pushes the start index by 1 each time it founds an occurence, and gets the max
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, bool> hashmap;
        int startindex = 0;
        int endlength = 0;
        int maxLength = 0;
        while (startindex < s.length() && endlength < s.length())
        {
            if (hashmap[s[endlength]] == false)
            { /* if not then add it and increase right pointer */
                hashmap[s[endlength]] = true;
                endlength++;
                maxLength = max(maxLength, endlength - startindex);
            }
            else
            {
                endlength = ++startindex;
                for (auto &pair : hashmap)
                    pair.second = false;
            }
        }
        return maxLength;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Same solution, but start from the new index
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> nmap;
        int start = 0;
        int end = 0;
        int maxLength = 0;
        int len = s.length();
        for (int end = 0; end < len; end++)
        {
            char curr = s[end];
            if (nmap.find(curr) == nmap.end() || nmap[curr] < start)
                maxLength = std::max(maxLength, end - start + 1);
            else
                start = nmap[curr] + 1;
            nmap[curr] = end;
        }
        return std::max(maxLength, end - start);
    }
};