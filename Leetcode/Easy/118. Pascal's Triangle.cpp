#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * @brief Dynamic programming
     * @details builds each row iteratively using values from the previous row (Combinatorial)
     * @complexity: Time: O(n²), Space: O(n²)
     */
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> rows(numRows);
        for (int i = 0; i < numRows; i++)
        {
            rows[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                rows[i][j] = rows[i - 1][j] + rows[i - 1][j - 1];
            }
        }
        return rows;
    }
};
