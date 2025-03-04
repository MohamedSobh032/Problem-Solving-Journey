/**
 * @brief First Solution
 * -- Time Complexity: O(n * 26 = n)
 * -- Space Complexity: O(256 = 1)
 * -- Fails when element is new but already mapped, or when exists an mapped to diff value
 */
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        std::unordered_map<char, char> arr;
        for (int i = 0; i < s.length(); i++)
        {
            if (arr.find(s[i]) == arr.end())
            {
                for (const auto &val : arr)
                    if (val.second == t[i])
                        return false;
            }
            else if (arr[s[i]] != t[i])
                return false;

            arr[s[i]] = t[i];
        }
        return true;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(256 * 2 = 1)
 * -- Same as above, but using two maps to save the indices to know if new, repeated, or correct
 */
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        std::unordered_map<char, int> indx_s;
        std::unordered_map<char, int> indx_t;
        for (int i = 0; i < s.length(); i++)
        {
            if (indx_s.find(s[i]) == indx_s.end())
                indx_s[s[i]] = i;

            if (indx_t.find(t[i]) == indx_t.end())
                indx_t[t[i]] = i;

            if (indx_s[s[i]] != indx_t[t[i]])
                return false;
        }
        return true;
    }
};
