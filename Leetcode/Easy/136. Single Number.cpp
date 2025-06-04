#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    /**
     * @brief XOR
     * @details XORs all elements; pairs cancel out and only the unique element remains
     * @complexity: Time: O(n), Space: O(1)
     */
    int singleNumber(vector<int> &nums)
    {
        int output = 0;
        for (const int num : nums)
            output ^= num;
        return output;
    }

    /**
     * @brief XOR
     * @details same as above, but uses STL to XOR all elements
     * @complexity: Time: O(n), Space: O(1)
     */
    int singleNumber(vector<int> &nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};