/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Counts the frequency of each character in the string
 *    then checks if the number of odd frequencies is less than or equal to k
 */
class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if (s.size() < k) return false;
        int arr[26] = {0}; int odds = 0;
        for (const char& c: s) arr[c - 'a']++;
        for (int i = 0; i < 26; i++) odds += arr[i] % 2;
        return odds <= k;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Same concept as above, but uses the concept of parity (XOR)
 */
class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if (s.size() < k) return false;
        unsigned int odds = 0; int counter = 0;
        for (const char& c: s) odds ^= 1 << (c - 'a');
        while (odds != 0) { counter += odds & 1; odds >>= 1; }
        return counter <= k;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Same solution as above, but uses the built-in function __builtin_popcount
 */
class Solution {
public:
    bool canConstruct(string s, int k) {
        
        if (s.size() < k) return false;
        unsigned int odds = 0; int counter = 0;
        for (const char& c: s) odds ^= 1 << (c - 'a');
        return __builtin_popcount(odds) <= k;
    }
};