/**
 * @brief First Solution
 * -- Time Complexity: O(1)
 * -- Space Complexity: O(1)
 * -- If the bit is set in num1, then set the bit in the result
 */
class Solution
{
public:
    bool get_bit(int x, int bit) { return x & (1 << bit); }
    void set_bit(int &x, int bit) { x |= 1 << bit; }
    int minimizeXor(int num1, int num2)
    {
        int result = 0, target = __builtin_popcount(num2), curr = 0, currentBit = 31;
        while (curr < target)
        {
            if (get_bit(num1, currentBit) || (target - curr > currentBit))
            {
                set_bit(result, currentBit);
                curr++;
            }
            currentBit--;
        }
        return result;
    }
};