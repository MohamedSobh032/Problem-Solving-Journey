/**
 * @brief First Solution
 * -- O(n^2)
 * -- Search for every element one by one
 * -- Worst solution
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int searchingFor = n;
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[j] == searchingFor) {
                    searchingFor--;
                    found = true;
                    break;
                }
            }
            if (found)
                found = false;
            else
                return searchingFor;
        }
        return searchingFor;
    }
};

/**
 * @brief Second Solution
 * -- O(nlogn)
 * -- Sort first, then condition
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        if (nums[0] != 0)
            return 0;
        if (nums[n-1] != n)
            return n;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[i + 1] - 1)
                return nums[i+1] - 1;
        }
        return 0;
    }
};

/**
 * @brief Third Solution
 * -- O(n)
 * -- Set the found elements to true, then search for the only false element
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        std::vector<bool> found(n + 1, false);

        for (int i = 0; i < n; i++)
            found[nums[i]] = true;

        for (int i = 0; i < n + 1; i++) {
            if (found[i] == false)
                return i;
        }

        return 0;
    }
};

/**
 * @brief Fourth Solution
 * -- O(n)
 * -- Add all the indices, and add all the values, the difference between them is the missing number
 * -- Best solution
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        // calculate indices sum
        int expected = n * (n + 1) / 2;
        // calculate actual sum
        int actual = 0;
        for (int i = 0; i < n; i++) 
            actual += nums[i];
        // return the missing
        return expected - actual;
    }
};