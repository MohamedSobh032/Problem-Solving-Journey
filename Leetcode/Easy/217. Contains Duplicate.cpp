#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @details Compares every pair of elements in the array
     * @complexity: Time: O(n^2), Space: O(1)
     */
    bool containsDuplicate(vector<int> &nums)
    {
        int length = nums.size();
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++)
                if (i != j && nums[i] == nums[j])
                    return true;
        return false;
    }

    /**
     * @details Converts the vector into a set. If duplicates exist, set size will be smaller.
     * @complexity: Time: O(n log n), Space: O(n)
     */
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> new_set(nums.begin(), nums.end());
        return new_set.size() != nums.size();
    }

    /**
     * @details Uses a hashmap for tracking seen values, if a value exists in the map, then there is duplicate
     * @complexity: Time: O(n), Space: O(n)
     */
    bool containsDuplicate(vector<int> &nums)
    {
        int length = nums.size();
        unordered_map<int, bool> hmap;
        for (int i = 0; i < length; i++)
        {
            if (hmap.find(nums[i]) != hmap.end())
                return true;
            hmap[nums[i]] = true;
        }
        return false;
    }

    /**
     * @details Sorts the array and checks adjacent elements for equality.
     * @complexity: Time: O(n log(n)), Space: O(1)
     */
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 1; i < length; i++)
            if (nums[i] == nums[i - 1])
                return true;
        return false;
    }
};
