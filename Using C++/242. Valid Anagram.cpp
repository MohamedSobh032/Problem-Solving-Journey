/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Hashmap Solution to get frequency of each character
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        std::unordered_map<char, int> nmap;
        for (const char &c : s)
            nmap[c]++;
        for (const char &c : t)
            nmap[c]--;

        for (auto it = nmap.begin(); it != nmap.end(); ++it)
            if (it->second != 0)
                return false;
        return true;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Same solution as above, but uses array to store the frequency of each character
 */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        std::vector<int> chars(26, 0);
        for (const char &c : s)
            chars[c - 'a']++;
        for (const char &c : t)
            chars[c - 'a']--;
            
        for (const int &i : chars)
            if (i != 0)
                return false;
        return true;
    }
};