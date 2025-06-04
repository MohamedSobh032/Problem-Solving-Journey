#include <stdint.h>

class Solution
{
public:
    /**
     * @brief Reverse bits
     * @details shifts output left and takes LSB from n, continues for 32 bits
     * @complexity: Time: O(1), Space: O(1)
     */
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t output = 0;
        for (int i = 0; i < 32; i++, n >>= 1)
            output = (output << 1) | (n & 1);
        return output;
    }
};