#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Two-pointer compression
     * @details uses a slow and fast pointer to overwrite duplicates in a sorted array
     * @complexity: Time: O(n), Space: O(1)
     */
    int removeDuplicates(vector<int> &nums)
    {
        int indx = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[indx] != nums[i])
                nums[++indx] = nums[i];

        return indx + 1;
    }
};
