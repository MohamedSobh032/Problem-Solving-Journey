/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- XOR all numbers, each pair cancel out
 */
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int n = 0;
        for (const int &num : nums)
            n ^= num;
        return n;
    }
};