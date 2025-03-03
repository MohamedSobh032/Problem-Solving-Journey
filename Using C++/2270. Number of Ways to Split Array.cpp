/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Gets the prefix sum of the array, then for each element in the array,
 *    it calculates the left and right sum, then checks if the right sum is less than or equal to the left sum
 */
class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        std::vector<long long> acc(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++)
            acc[i] = static_cast<long long>(nums[i]) + acc[i - 1];

        long long counter = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            long long left = acc[i];
            long long right = acc.back() - left;
            if (right <= left)
                counter++;
        }
        return counter;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Uses STL accumulate to get total sum first, then maintains a running prefix sum,
 *    comparing each split point by subtracting prefix sum from total sum to get right side sum
 */
class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long counter = 0;
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        std::vector<long long> acc(nums.size(), 0);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            acc[i] = static_cast<long long>(nums[i]) + (i != 0 ? acc[i - 1] : 0);
            counter += (sum - acc[i] <= acc[i]);
        }
        return counter;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Maintains two running sums: left sum growing from left to right,
 *    and total sum being reduced as we progress, eliminating need for prefix array
 */
class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long counter = 0;
        long long sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long left = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            left += nums[i];
            sum -= nums[i];
            counter += (sum <= left);
        }
        return counter;
    }
};