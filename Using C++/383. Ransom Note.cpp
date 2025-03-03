/**
 * @brief First Solution
 * -- Time Complexity: O(N + M)
 * -- Space Complexity: O(26 = 1)
 * -- freq of ransom - freq of magazine, if one char has more than 0, it cannot be created
 */
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int arr[26] = {0};
        for (const auto &chr : magazine)
            arr[chr - 'a']++;
            
        for (const auto &chr : ransomNote)
        {
            if (arr[chr - 'a'] <= 0)
                return false;
            arr[chr - 'a']--;
        }
        return true;
    }
};