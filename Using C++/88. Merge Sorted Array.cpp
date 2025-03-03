/**
 * @brief First Solution
 * -- Time Complexity: O(n + m)
 * -- Space Complexity: O(1)
 * -- Uses 3 pointers to point to the last element of the 3 arrays
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0)
            nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
};