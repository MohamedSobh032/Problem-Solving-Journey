#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Bounding Box Traversal
     * @details traverses the given 2D matrix in using bounding box method
     * @complexity: Time: O(m * n), Space: O(1) extra (excluding output)
     */
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int total = matrix.size() * matrix[0].size();
        int rowEnd = matrix.size() - 1, colEnd = matrix[0].size() - 1;
        int rowStart = 0, colStart = 0;
        std::vector<int> spir;

        while (spir.size() < total)
        {
            // print upper row
            for (int i = colStart; i <= colEnd; i++)
                spir.push_back(matrix[rowStart][i]);
            rowStart++;

            // print right col
            for (int i = rowStart; i <= rowEnd; i++)
                spir.push_back(matrix[i][colEnd]);
            colEnd--;

            if (spir.size() == total)
                break;

            // print lower row
            for (int i = colEnd; i >= colStart; i--)
                spir.push_back(matrix[rowEnd][i]);
            rowEnd--;

            // print left col
            for (int i = rowEnd; i >= rowStart; i--)
                spir.push_back(matrix[i][colStart]);
            colStart++;
        }
        return spir;
    }
};