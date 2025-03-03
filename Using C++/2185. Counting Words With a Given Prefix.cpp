/**
 * @brief First Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(1)
 * -- For each word, check if the prefix is present in the word
 */
class Solution
{
public:
    int prefixCount(vector<string> &words, string pref)
    {
        int count = 0;
        for (const auto &word : words)
            if (word.find(pref) == 0)
                count++;
        return count;
    }
};