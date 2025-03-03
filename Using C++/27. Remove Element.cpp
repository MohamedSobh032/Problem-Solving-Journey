/**
 * @brief First Solution
 * -- Time complexity: O(n)
 * -- Space complexity: O(1)
 * -- Iterates on the array and if the element is different from the value to remove, it is copied to the new position.
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {

        int newlen = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[newlen++] = nums[i];
        return newlen;
    }
};