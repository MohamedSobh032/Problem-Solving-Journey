#include <vector>
#include <bit>
using namespace std;

class Solution
{
public:
    /**
     * @brief Bit Manipulation (Suffix Leftmost 1 Search)
     * @details finds the suffix leftmost one bit and flips it to generate the minimal j.
     * @complexity: Time: O(n * 32), Space: O(1)
     */
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (int &num : nums)
        {
            if (num & 1)
            {
                // from the suffix, find the leftmost 1, toggle it to 0
                for (int i = 1; i < 32; i++)
                {
                    int bit = num & (1 << i);
                    if (bit == 0)
                    {
                        num = num ^ (1 << (i - 1));
                        break;
                    }
                }
            }
            // if even, it is impossible to be the same
            else
            {
                num = -1;
            }
        }
        return nums;
    }

    /**
     * @brief Bit Manipulation (Suffix Leftmost 1 Search)
     * @details the same but using countr_one instead.
     * @complexity: Time: O(n), Space: O(1)
     */
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        for (int &num : nums)
        {
            if (num & 1)
            {
                // from the suffix, find the leftmost 1, toggle it to 0
                int i = countr_one((unsigned)num) - 1;
                num ^= (1 << i);
            }
            // if even, it is impossible to be the same
            else
            {
                num = -1;
            }
        }
        return nums;
    }
};