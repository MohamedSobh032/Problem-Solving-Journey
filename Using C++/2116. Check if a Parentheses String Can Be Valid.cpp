/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Sweeps from left once and from right once, if closed bracket is found, it cancels out with either an unlocked or open bracket
 *    From right to left, if the balance is greater than 0, it means there are more open brackets than closed brackets
 */
class Solution {
public:
    bool canBeValid(string s, string locked) {

        int length = s.size();
        if (length % 2) return false;
        int open_brackets = 0, unlocked = 0, balance = 0;
        for (int i = 0; i < length; i++) {
            if (locked[i] == '0') unlocked++;
            else if (s[i] == '(') open_brackets++;
            else if (s[i] == ')') {
                if (open_brackets > 0) open_brackets--;
                else if (unlocked > 0) unlocked--;
                else return false;
            }
        }
        for (int i = length - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                balance--; unlocked--;
            } else if (s[i] == '(') {
                balance++; open_brackets--;
            } else if (s[i] == ')') balance--;

            if (balance > 0) return false;
            if (unlocked == 0 && open_brackets == 0) break;
        }
        return open_brackets <= 0;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Counts the minimum and maximum number of open brackets
 *    if an closed bracket is found and the minimum is greater, it means there are more closed brackets than open brackets
 */
class Solution {
public:   
    bool canBeValid(string s, string locked) {
        
        int n = s.size(), minOpen = 0, maxOpen = 0;
        if (n % 2) return false;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                maxOpen++;
                minOpen = minOpen == 0 ? 1 : minOpen - 1;
            } else if (s[i] == '(') {
                minOpen++; maxOpen++;
            } else {
                maxOpen--;
                minOpen = minOpen == 0 ? 1 : minOpen - 1;
                if (minOpen > maxOpen) return false;
            }
        }
        return minOpen == 0;
    }
};