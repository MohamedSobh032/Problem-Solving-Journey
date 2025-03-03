/**
 * @brief First Solution
 * --> Time Complexity: O(m*n)
 * --> Space Complexity: O(1)
 * --> Clear on each row/column when finishing the iteration
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        std::vector<int> spiral;
        int m = matrix[0].size();
        int n = matrix.size();

        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();

        while (left < right && top < bottom)
        {
            for (int i = left; i < right; i++)
                spiral.push_back(matrix[top][i]);
            top++;

            for (int i = top; i < bottom; i++)
                spiral.push_back(matrix[i][right - 1]);
            right--;

            if (spiral.size() == m * n)
                break;

            for (int i = right - 1; i >= left; i--)
                spiral.push_back(matrix[bottom - 1][i]);
            bottom--;

            for (int i = bottom - 1; i >= top; i--)
                spiral.push_back(matrix[i][left]);
            left++;
        }
        return spiral;
    }
};