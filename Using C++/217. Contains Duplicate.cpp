/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(1)
 * -- Brute-force approach, by checking all possible pairs
 */
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size(); j++)
                if (i != j && nums[i] == nums[j])
                    return true;
        return false;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(1)
 * -- Sorting approach, compares each element with the element after
 */
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1])
                return true;
        return false;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Hashmap approach
 */
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        std::unordered_map<int, bool> mp;
        for (const int &num : nums)
        {
            if (mp[num])
                return true;
            mp[num] = true;
        }
        return false;
    }
};