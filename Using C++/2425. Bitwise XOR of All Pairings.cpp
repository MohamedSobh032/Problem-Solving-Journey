/**
 * @brief First Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(1)
 * -- XOR all the numbers in nums1 with all the numbers in nums2
 */
class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int nums3 = 0;
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++)
                nums3 ^= (nums1[i] ^ nums2[j]);
        return nums3;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n + m)
 * -- Space Complexity: O(1)
 * -- if the size of one is even, then the other will have no effect on the result
 *    this remove the unnecessary XOR operations
 */
class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size(), num3 = 0;
        if (n % 2 == 0 && m % 2 == 0)
            return 0;

        if (n % 2)
            for (const int &n : nums2)
                num3 ^= n;

        if (m % 2)
            for (const int &n : nums1)
                num3 ^= n;

        return num3;
    }
};