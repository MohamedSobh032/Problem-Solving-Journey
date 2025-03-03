/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Two pointer method, where the first pointer is the index of the last unique element
 * -- The second pointer is the index of the current element being checked
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (!nums.size())
            return 0;
        int indx = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[indx] != nums[i])
                nums[++indx] = nums[i];
        return indx + 1;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- Using a set to store the unique elements, then copy the set to the vector
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        set<int> s(nums.begin(), nums.end());
        nums = vector<int>(s.begin(), s.end());
        return nums.size();
    }
};