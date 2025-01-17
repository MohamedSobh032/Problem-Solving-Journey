/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Each element occurs twice in the original array, meaning the xor-sum should be 0
 * -- If the xor-sum is 0, then the original array exists
 */
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int x = 0;
        for (const int& d: derived) x ^= d;
        return !static_cast<bool>(x);
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Same solution as above, but using STL functions
 */
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        return !std::accumulate(derived.begin(), derived.end(), 0, std::bit_xor<>());
    }
};