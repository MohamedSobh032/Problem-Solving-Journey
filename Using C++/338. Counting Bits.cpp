/**
 * @brief First Solution
 * -- O(n)
 * -- Ans is the perivous + 1 if odd, else same as previous
 */
class Solution
{
public:
    vector<int> countBits(int n)
    {
        std::vector<int> ans(n + 1, 0);
        ans[0] = 0;
        for (int i = 1; i < n + 1; i++)
            ans[i] = ans[i >> 1] + (i & 1);
        return ans;
    }
};