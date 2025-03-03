/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Puts the frequency in a hashmap and return the highest
 */
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> nmap;
        for (const auto &num : nums)
            nmap[num]++;

        int n = nums.size() / 2;
        for (const auto &pair : nmap)
            if (pair.second > n)
                return pair.first;
        return -1;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nlogn)
 * -- Space Complexity: O(1)
 * -- Sorts and check for repeats, if reached majority returns it
 */
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Moore Voting Algorithm
 */
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, candidate = 0;
        for (const int &num : nums)
        {
            if (count == 0)
                candidate = num;
            count += num == candidate ? 1 : -1;
        }
        return candidate;
    }
};