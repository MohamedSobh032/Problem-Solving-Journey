/**
 * @brief First Solution
 * -- Time Complexity: O(logn base 26)
 * -- Space Complexity: O(logn base 26)
 * -- Simply convert the number of base 10 to the base 26
 */
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        std::vector<char> arr;
        while (columnNumber > 0)
        {
            columnNumber--;
            int actual = columnNumber % 26;
            arr.push_back('A' + actual);
            columnNumber /= 26;
        }
        std::reverse(arr.begin(), arr.end());
        return std::string(arr.begin(), arr.end());
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(logn base 26)
 * -- Space Complexity: O(logn base 26)
 * -- Same as above but with string instead of vector
 */
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string title = "";
        while (columnNumber > 0)
        {
            columnNumber--;
            title = char((columnNumber % 26) + 'A') + title;
            columnNumber /= 26;
        }
        return title;
    }
};