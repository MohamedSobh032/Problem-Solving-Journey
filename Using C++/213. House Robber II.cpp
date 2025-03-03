/**
 * @brief First/Only Solution
 * ---> O(n)
 * ---> Same as house robber, applying it twice, once without the last, once without the first
 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];

        std::vector<int> subvector1(nums.begin() + 1, nums.end());
        std::vector<int> subvector2(nums.begin(), nums.end() - 1);
        return std::max(help(subvector1), help(subvector2));
    }

    int help(vector<int> &nums)
    {
        int n1 = 0;
        int n2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = std::max(nums[i] + n1, n2);
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};