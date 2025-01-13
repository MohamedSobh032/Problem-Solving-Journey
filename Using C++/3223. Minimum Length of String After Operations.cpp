/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Gets the frequency of each character in the string
 *    then subtracts 2 from each frequency with counting
 */
class Solution {
public:
    int minimumLength(string s) {
        
        int length = s.size(); int arr[26] = {};
        for (const auto& c: s) arr[c - 'a']++;
        for (int i = 0; i < 26; i++) { while (arr[i] >= 3) { arr[i] -= 2; length -= 2; } }
        return length;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Gets the frequency of each character in the string
 *    if the character exists, adds 1 if odd and 2 if even
 */
class Solution {
public:
    int minimumLength(string s) {
        
        int length = 0; int arr[26] = {};
        for (const auto& c: s) arr[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == 0) continue;
            length += (arr[i] % 2) ? 1 : 2;
        }
        return length;
    }
};