/**
 * @brief First/Only Solution
 * -- O(1)
 * -- Get the left-most bit in the n, pushes it in a new int, and shift lefts the n
 */
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rotated = 0;
        // Iterate 32 times
        for (int i = 0; i < 32; i++) {
            rotated = (rotated << 1) | (n & 1);
            n >>= 1;
        }
        return rotated;
    }
};