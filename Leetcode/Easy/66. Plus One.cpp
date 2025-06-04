#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Adds one to the number represented by the digits vector
     * @details Starts from the least significant digit (end of vector), handles carry if the digit becomes 10.
     *          If carry continues past the most significant digit, inserts a new digit `1` at the front.
     * @complexity: Time: O(n), Space: O(1)
     */
    vector<int> plusOne(vector<int> &digits)
    {
        int i = digits.size() - 1;
        bool carry_forward = true;
        while (carry_forward)
        {
            if (i == -1)
            {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            int digit = digits[i] + 1;
            carry_forward = (digit == 10);
            digits[i] = digit % 10;
            i--;
        }
        return digits;
    }

    /**
     * @brief Adds one to the number represented by the digits
     * @details Starts from the last digit and propagates carry only if needed
     * @complexity: Time: O(n), Space: O(1)
     */
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};