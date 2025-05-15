#include <string>
#include <cctype>
#include <iostream>
using namespace std;

class Solution
{
public:
    /**
     * @brief Two-Pointer
     * @details compares the characters at the two pointers and moves them accordingly
     * @complexity: Time: O(n), Space: O(1)
     */
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            while (left < s.size() && !isalnum(s[left]))
                left++;
            if (left >= s.size())
                break;
            while (!isalnum(s[right]))
                right--;
            if (tolower(s[left++]) != tolower(s[right--]))
                return false;
        }
        return true;
    }

    /**
     * @brief String Filtering, Two-Pointer
     * @details filters the string to only alphanumeric characters and converts them to lowercase, then use two-pointer
     * @complexity: Time: O(n), Space: O(n)
     */
    bool isPalindrome(string s)
    {
        string filtered = "";
        int len = s.size();
        for (int i = 0; i < len; i++)
            if (isalnum(s[i]))
                filtered += tolower(s[i]);

        int left = 0, right = filtered.size() - 1;
        while (left < right)
            if (filtered[left++] != filtered[right--])
                return false;
        return true;
    }
};
