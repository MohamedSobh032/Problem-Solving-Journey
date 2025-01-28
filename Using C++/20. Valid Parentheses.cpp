/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n) 
 * -- Using stack to save the open brackets, then check if the closing brackets are in the correct order
 */
class Solution {
public:
    bool isValid(string s) {

        std::stack<char> space;
        for (const char& c: s) {
            if (c == '{' || c == '(' || c == '[') { space.push(c); continue; }
            if (space.empty()) return false;
            char last = space.top();
            if (c == '}' && last != '{') return false;
            if (c == ')' && last != '(') return false;
            if (c == ']' && last != '[') return false;
            space.pop();
        }
        return space.empty();
    }
};