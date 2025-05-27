#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:

    /**
     * @brief Stack
     * @details uses a stack to keep track of opening parentheses and checks for matching pairs
     * @complexity: Time: O(n), Space: O(n)
     */
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stk.push(s[i]);
            else
            {
                if (stk.empty())
                    return false;
                char top = stk.top();
                if (
                    top == '(' && s[i] == ')' ||
                    top == '{' && s[i] == '}' ||
                    top == '[' && s[i] == ']')
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }

    /**
     * @brief Stack with Mapping
     * @details uses a mapping to check for matching pairs of parentheses
     * @complexity: Time: O(n), Space: O(n)
     */
    bool isValid(string s)
    {
        stack<char> stk;
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        for (const char &c : s)
        {
            if (mapping.find(c) == mapping.end())
                stk.push(c);
            else if (!stk.empty() && mapping[c] == stk.top())
                stk.pop();
            else
                return false;
        }
        return stk.empty();
    }
};