#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Prefix & Suffix Product
     * @details Compute left and right products separately, then multiply them in a single pass
     * @complexity: Time: O(n), Space: O(1) (excluding output)
     */
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output(n, 1);

        int left = 1;
        for (int i = 0; i < n; i++)
        {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            output[i] *= right;
            right *= nums[i];
        }

        return output;
    }
};