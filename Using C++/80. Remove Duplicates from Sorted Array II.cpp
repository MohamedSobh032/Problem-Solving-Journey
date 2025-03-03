/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Two pointer method, checks for repeats, if repeated, set the flag, if new number, reset the flag
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.size() <= 2)
            return nums.size();

        int index = 0;
        bool flag = false;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[index] == nums[i])
            {
                if (flag == false)
                    nums[++index] = nums[i];
                flag = true;
            }
            else
            {
                nums[++index] = nums[i];
                flag = false;
            }
        }
        return index + 1;
    }
};