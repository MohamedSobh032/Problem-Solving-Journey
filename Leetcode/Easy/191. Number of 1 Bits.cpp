class Solution
{
public:
    /**
     * @brief Hamming Weight General Algorithm
     * @details counts the current bit and shift the remaining with recursion.
     * @complexity: Time: O(log n), Space: O(log n)
     */
    int hammingWeight(int n)
    {
        return n == 0 ? 0 : (n & 1) + hammingWeight(n >> 1);
    }
};