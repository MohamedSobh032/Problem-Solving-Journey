#include <vector>
#include <climits>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @brief Brute Force Absolute Difference Search
     * @details checks all possible pairs to find the minimum absolute difference, then collects matching pairs.
     * @complexity: Time: O(n^2 log n), Space: O(1)
     */
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();

        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    minimum = std::min(minimum, abs(arr[i] - arr[j]));
            }
        }

        vector<vector<int>> vec;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (abs(arr[i] - arr[j]) == minimum && arr[i] < arr[j])
                    vec.push_back({arr[i], arr[j]});
            }
        }

        sort(vec.begin(), vec.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        return vec;
    }

    /**
     * @brief Sorting and Adjacent Difference Scan
     * @details sorts the array and compares only adjacent elements to find the minimum absolute difference.
     * @complexity: Time: O(n log n), Space: O(1)
     */
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        std::sort(arr.begin(), arr.end());

        int minimum = INT_MAX;
        for (int i = 1; i < n; i++)
            minimum = std::min(minimum, arr[i] - arr[i - 1]);

        vector<vector<int>> vec;
        for (int i = 1; i < n; i++)
            if (arr[i] - arr[i - 1] == minimum)
                vec.push_back({arr[i - 1], arr[i]});

        return vec;
    }
};