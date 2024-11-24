
/**
 * @brief First Solution
 * -- O(n)
 * -- Using stack
 */
class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> myStack;
        int len = s.length();
        char close = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') { 
                myStack.push(s[i]);
                continue;
            }
            if (myStack.empty())
                return false;
            close = myStack.top();
            if (s[i] == ')' && close != '(')
                return false;
            else if (s[i] == ']' && close != '[')
                return false;
            else if (s[i] == '}' && close != '{')
                return false;
            myStack.pop();
        }
        if (!myStack.empty())
            return false;
        return true;
    }
};