/**
 * @brief First Solution
 * -- Time Complexity: O(2^n)
 * -- Space Complexity: O(2^n)
 * -- Brute-force solution
 */
class Solution
{
public:
    void rec(const std::string &s, std::string curr, int index, std::unordered_map<std::string, int> &nmap)
    {
        if (curr.size() == 3)
        {
            if (curr[0] == curr[2])
                nmap[curr] = 1;
            return;
        }
        if (index == s.size())
            return;

        rec(s, curr, index + 1, nmap);
        rec(s, curr + s[index], index + 1, nmap);
    }

    int countPalindromicSubsequence(string s)
    {
        int counter = 0;
        std::unordered_map<std::string, int> nmap;
        rec(s, "", 0, nmap);
        for (const auto &p : nmap)
            counter += p.second;
        return counter;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Stores the first and last occurence of each character in the string,
 *    then iterates over the characters and counts the unique characters inbetween
 */
class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        int ans = 0;
        std::unordered_map<char, std::pair<int, int>> M;

        for (int i = 0; i < s.size(); i++)
        {
            if (M.find(s[i]) == M.end())
                M[s[i]].first = i;
            M[s[i]].second = i;
        }

        std::unordered_set<char> uniqueChars;
        for (auto &[ch, positions] : M)
        {
            int left = positions.first, right = positions.second;
            if (right - left <= 1)
                continue;
            for (int i = left + 1; i < right; i++)
                uniqueChars.insert(s[i]);
            ans += uniqueChars.size();
            uniqueChars.clear();
        }

        return ans;
    }
};