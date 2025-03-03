/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Iterates on the string and counts the number of segments
 *    by checking if the current character is not a space and the previous character is a space.
 */
class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
            if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
                count++;

        return count;
    }
};