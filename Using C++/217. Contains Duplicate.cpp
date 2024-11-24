/**
 * @brief First Solution
 * -- O(n^2)
 * -- Iterate with a 2 for loops on each element to find duplicates
 * -- Worst solution
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j && nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
};

/**
 * @brief Second Solution
 * -- O(nlogn)
 * -- Sort, then compare each element with the element after
 * -- Second best
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

/**
 * @brief Third Solution
 * -- O(n)
 * -- Use a hashmap to input each element while iterating, return if element exists
 */
 class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (const int& num : nums) {
            if (mp[num])
                return true;
            mp[num] = true;
        }
        return false;
    }
};