/**
 * @brief First Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(1)
 * -- Brute-force solution
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums.size(); j++)
                if (nums[i] == nums[j] && i != j)
                    return nums[i];
        return -1;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Floyd's Tortoise and Hare (Cycle Detection)
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};