/**
 * @brief First Solution
 * -- O(n^2)
 * -- Worst solution
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            int toGet = target - nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (toGet == nums[j] && i != j)
                    return {i, j};
            }
        }
        return {};
    }
};


/**
 * @brief Second Solution
 * -- O(n)
 * -- Applies only to sorted arrays
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int total = nums[l] + nums[r];
            if (total == target)
                return {l, r};
            if (total < target)
                l++;
            if (total > target)
                r--;
        }
        return {};
    }
};

/**
 * @brief Third Solution
 * -- O(n)
 * -- Best solution
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nmap;
        for (int i = 0; i < nums.size(); i++) {
            int toGet = target - nums[i];
            if (nmap.find(toGet) != nmap.end())
                return {nmap[toGet], i};
            nmap.insert({nums[i], i});
        }
        return {};
    }
};
 