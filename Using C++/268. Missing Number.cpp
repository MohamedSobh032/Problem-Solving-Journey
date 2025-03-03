/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(1)
 * -- Brute-force approach, search for every element one by one
 * -- Worst solution
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size(), searchingFor = n;
        bool found = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == searchingFor)
                {
                    searchingFor--;
                    found = true;
                    break;
                }
            }

            if (!found)
                return searchingFor;
        }

        return searchingFor;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(1)
 * -- Sorting solution
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        if (nums[0] != 0)
            return 0;
        if (nums[n - 1] != n)
            return n;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != nums[i + 1] - 1)
                return nums[i + 1] - 1;

        return 0;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Set the found elements to true, then search for the only false element
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        std::vector<bool> found(n + 1, false);
        for (int i = 0; i < n; i++)
            found[nums[i]] = true;

        for (int i = 0; i < n + 1; i++)
            if (!found[i])
                return i;

        return 0;
    }
};

/**
 * @brief Fourth Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Add all the indices, and add all the values, the difference between them is the missing number
 */
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {

        int n = nums.size();
        return std::accumulate(nums.begin(), nums.end(), 0) - (n * (n + 1) / 2);
    }
};