/**
 * @brief First Solution
 * -- Time Complexity: O(n * k)
 * -- Space Complexity: O(1)
 * -- Iterates each step at once
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        for (int _ = 0; _ < k; _++)
        {
            int rotator = nums[0];
            for (int i = 1; i < nums.size(); i++)
                std::swap(nums[i], rotator);
            nums[0] = rotator;
        }
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Puts the element in the correct position of the new array
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        std::vector<int> newArr(nums.size());
        for (int i = 0; i < nums.size(); i++)
            newArr[(i + k) % nums.size()] = nums[i];
        nums = newArr;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Rotates the full array, then rotate the left of the k, then rotate the right of the k
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};