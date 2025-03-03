/**
 * @brief First/Only Solution
 * -- O(n)
 * -- Couldn't implement it using sliding window, since I couldn't find pushing the left boundary condition
 * -- Implemented as half sub-sliding window from the left, then do the same thing from the right
 */
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maximum = INT_MIN;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prod *= nums[i];
            maximum = max(maximum, prod);
            prod = (prod == 0) ? 1 : prod;
        }
        
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prod *= nums[i];
            maximum = max(maximum, prod);
            prod = (prod == 0) ? 1 : prod;
        }
        return maximum;
    }
};