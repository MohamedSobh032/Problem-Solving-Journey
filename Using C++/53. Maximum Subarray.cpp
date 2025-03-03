/**
 * @brief First Solution
 * -- m4 3aref agib complexity
 * -- Recursive brute-force
 */
class Solution
{
public:
    void rec(vector<int> &nums, vector<int> currList, int index, int &maximum)
    {
        if (index == nums.size())
        {
            int localMax = 0;
            for (int i = 0; i < currList.size(); i++)
                localMax += currList[i];
            maximum = max(maximum, localMax);
            return;
        }
        rec(nums, currList, index + 1, maximum);
        currList.push_back(nums[index]);
        rec(nums, currList, index + 1, maximum);
    }

    int maxSubArray(vector<int> &nums)
    {
        int maximum = INT_MIN;
        rec(nums, {}, 0, maximum);
        return maximum;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Sliding Window
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maximum = max(maximum, sum);
            sum = max(sum, 0);
        }
        return maximum;
    }
};