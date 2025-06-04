#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Bottom-up DP
     * @details ans[i] = ans[i >> 1] + (i & 1)
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        for (int i = 1; i < n + 1; i++)
            ans[i] = ans[i >> 1] + (i & 1);
        return ans;
    }
};