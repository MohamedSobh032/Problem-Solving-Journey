#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute-force
     * @details combines all possible pairs of lines and returns the maximum area formed
     * @complexity: Time: O(n^2), Space: O(1)
     */
    int maxArea(vector<int> &height)
    {
        int max_area = INT_MIN, n = height.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                int curr_area = abs(i - j) * min(height[i], height[j]);
                max_area = max(max_area, curr_area);
            }
        }
        return max_area;
    }

    /**
     * @brief Two-pointer
     * @details moves the left or right pointer based on which side has the shorter line since it limits the maximum possible area
     * @complexity: Time: O(n), Space: O(1)
     */
    int maxArea(vector<int> &height)
    {
        int max_area = INT_MIN;
        int l = 0, r = height.size() - 1;
        while (l < r)
        {
            int curr_area = (r - l) * min(height[l], height[r]);
            max_area = max(max_area, curr_area);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};