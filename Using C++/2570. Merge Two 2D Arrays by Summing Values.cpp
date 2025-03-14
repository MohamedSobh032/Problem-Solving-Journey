/**
 * @brief First Solution
 * -- Time Complexity: O(N + M)
 * -- Space Complexity: O(N + M)
 * -- Add all elements in an ordered map and then inserts them into a matrix
 */
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        std::map<int, int> nmap;
        for (const auto &entry : nums1)
            nmap[entry[0]] = entry[1];
        for (const auto &entry : nums2)
            nmap[entry[0]] += entry[1];

        std::vector<std::vector<int>> result;
        for (const auto &[id, data] : nmap)
            result.push_back({id, data});

        return result;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(N + M)
 * -- Space Complexity: O(N + M)
 * -- Two pointer approach
 */
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        int N1 = nums1.size(), N2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;

        vector<vector<int>> mergedArray;
        while (ptr1 < N1 && ptr2 < N2)
        {
            if (nums1[ptr1][0] == nums2[ptr2][0])
            {
                mergedArray.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            }
            else if (nums1[ptr1][0] < nums2[ptr2][0])
                mergedArray.push_back(nums1[ptr1++]);
            else
                mergedArray.push_back(nums2[ptr2++]);
        }

        while (ptr1 < N1)
            mergedArray.push_back(nums1[ptr1++]);

        while (ptr2 < N2)
            mergedArray.push_back(nums2[ptr2++]);

        return mergedArray;
    }
};