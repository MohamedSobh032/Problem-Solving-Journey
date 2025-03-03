
/**
 * @brief First Solution
 * -- O(n)
 * -- Works only on positive numbers
 */
class Solution
{
public:
    int getSum(int a, int b)
    {
        int aBit = 0, int bBit = 0;
        int sum = 0, int carry = 0;
        int i = 0;

        while (a != 0 || b != 0)
        {
            // Get current bit
            aBit = a & 1;
            bBit = b & 1;
            // Get current sum of bits
            int currSum = (aBit ^ bBit);
            sum |= (int)((currSum ^ carry) << i++);
            carry = (aBit & bBit) | (carry & currSum);
            // Shift for the next bit
            a = a >> 1;
            b = b >> 1;
        }
        sum |= carry << i;
        return sum;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- This solution requires watching tutorial on bit manipulation addition (same process for logic-1 course)
 * -- Best solution
 */
class Solution
{
public:
    int getSum(int a, int b)
    {
        if (b == 0)
            return a;

        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};

/**
 * @brief Third Solution
 * -- O(1)
 * -- Pure math, very slow but very genius
 */
class Solution
{
public:
    int getSum(int a, int b)
    {
        return std::log2(pow(2, a) * pow(2, b));
    }
};