/**
 * @brief First Solution
 * -- O(n^2)
 * -- Iterates on all elements twice with multiplication
 * -- Worst solution
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int multiply = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (j != i)
                    multiply *= nums[j];
            }
            v[i] = multiply;
        }
        return v;
    }
};


/**
 * @brief Second Solution
 * -- O(n) three times
 * -- Gets the left products
 * -- Gets the right products
 * -- ans = left * right
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> vecLeft(nums.size(), 1);
        // Left products
        // [1, 2, 3, 4]
        // [1, 1, 1, 1]
        // [1, 1, 2, 6]
        for (int i = 1; i < nums.size(); i++)
            vecLeft[i] = vecLeft[i - 1] * nums[i - 1];

        vector<int> vecRight(nums.size(), 1);
        // Right products
        // [1, 2, 3, 4]
        // [1, 1, 1, 1]
        // [24, 12, 4, 1]
        for (int i = nums.size() - 2; i >= 0; i--)
            vecRight[i] *= vecRight[i + 1] * nums[i + 1];

        for (int i = 0 ; i < vecLeft.size(); i++)
            vecLeft[i] = vecLeft[i] * vecRight[i];

        return vecLeft;
    }
};