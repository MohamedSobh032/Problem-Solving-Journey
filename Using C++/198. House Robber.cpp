
/**
 * @brief First Solution
 * -- O(n)
 * -- Dynamic Programming approach
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
    
        vector<int> n(nums.size(), 0);
        n[0] = nums[0];
        n[1] = std::max(nums[0], nums[1]);
        for (int i = 2; i < n.size(); i++)
            n[i] = std::max(nums[i] + n[i - 2], n[i - 1]);
        return n[nums.size() - 1];
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Dynamic Programming approach
 * -- Faster because of less allocations
 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n1 = 0, n2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = std::max(nums[i] + n1, n2);
            n1 = n2;
            n2 = temp;
        }
        return n2;
    }
};