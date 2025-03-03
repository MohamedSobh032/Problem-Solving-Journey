/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Inserts alphanumeric characters in a new vector, then palindrome check
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        std::vector<char> n(s.size(), 0);
        int length = 0;
        for (const char &c : s)
        {
            if (c >= 'a' && c <= 'z')
                n[length++] = c;
            else if (c >= 'A' && c <= 'Z')
                n[length++] = c + 32;
            else if (c >= '0' && c <= '9')
                n[length++] = c;
        }

        for (int i = 0; i < length / 2; i++)
            if (n[i] != n[length - i - 1])
                return false;
        return true;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Same solution as above, but using C++ libraries
 */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        std::vector<char> n(s.size(), 0);
        int length = 0;
        for (const char &c : s)
            if (isalnum(c))
                n[length++] = tolower(c);

        for (int i = 0; i < length / 2; i++)
            if (n[i] != n[length - i - 1])
                return false;
        return true;
    }
};