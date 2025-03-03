/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(1)
 * -- Brute-force approach by checking all possible pairs
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            int toGet = target - nums[i];
            for (int j = 0; j < nums.size(); j++)
                if (toGet == nums[j] && i != j)
                    return {i, j};
        }
        return {};
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Two-pointer approach, but requires sorted array
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int total = nums[l] + nums[r];
            if (total == target)
                return {l, r};
            if (total < target)
                l++;
            else
                r--;
        }
        return {};
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Using hash map to store the index of the elements
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        std::unordered_map<int, int> nmap;
        for (int i = 0; i < nums.size(); i++)
        {
            int toGet = target - nums[i];
            if (nmap.find(toGet) != nmap.end())
                return {nmap[toGet], i};
            nmap.insert({nums[i], i});
        }
        return {};
    }
};
