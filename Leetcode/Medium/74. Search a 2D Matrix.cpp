#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Binary Search on Matrix
     * @details treats the 2D matrix as a flat sorted array and applies binary search on it
     * @complexity: Time: O(log(n * m)), Space: O(1)
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int size = n * m;

        int l = 0, r = size - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};