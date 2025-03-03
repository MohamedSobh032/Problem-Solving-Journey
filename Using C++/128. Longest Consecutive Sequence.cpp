/**
 * @brief First Solution
 * -- Time complexity: O(n)
 * -- Space complexity: O(n)
 * -- If the number is the beginning, start counting the length of the consecutive sequence and finding the max
 */
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        std::unordered_set<int> set_num(nums.begin(), nums.end());
        int length = 0;
        for (const int &n : nums)
        {
            if (set_num.find(n - 1) != set_num.end())
                continue;
            int curr = 1;
            while (set_num.count(n + curr))
                curr++;
            length = std::max(length, curr);
            if (length > nums.size() / 2)
                break;
        }
        return length;
    }
};