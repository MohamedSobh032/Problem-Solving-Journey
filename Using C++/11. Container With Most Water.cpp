/**
 * @brief First Solution
 * -- O(n^2)
 * -- Brute force solution
 */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        // iterate on all possible combinations
        for (int i = 0; i < height.size(); i++)
            for (int j = i + 1; j < height.size(); j++)
                max_area = std::max(max_area, abs(i - j) * std::min(height[i], height[j]));

        return max_area;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Two pointer approach
 */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int max_area = 0;
        while (l < r)
        {
            max_area = std::max(max_area, (r - l) * std::min(height[r], height[l]));
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return max_area;
    }
};