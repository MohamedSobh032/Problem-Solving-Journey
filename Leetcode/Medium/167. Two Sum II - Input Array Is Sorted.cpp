#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Two-pointer
     * @details since sorted, if larger then move left, if smaller then move right, else return it.
     * @complexity: Time: O(n), Space: O(1)
     */
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            int current_sum = numbers[l] + numbers[r];
            if (current_sum == target)
                return {l + 1, r + 1};
            else if (current_sum < target)
                l++;
            else
                r--;
        }
        return {};
    }
};