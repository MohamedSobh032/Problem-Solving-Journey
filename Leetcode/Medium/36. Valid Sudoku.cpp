#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    /**
     * @brief Manual Grid Checks
     * @details Check rows, columns, and subgrids individually using brute-force comparisons
     * @complexity: Time: O(1), Space: O(1)
     * @note this solution is much faster because it is hardcoded
     */
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                for (int k = 0; k < 9; k++)
                    if (k != i && board[i][j] == board[k][j])
                        return false;

                for (int k = 0; k < 9; k++)
                    if (k != j && board[i][j] == board[i][k])
                        return false;

                int y1, y2, x1, x2;
                if (i % 3 == 0)
                {
                    y1 = i + 1;
                    y2 = i + 2;
                }
                else if (i % 3 == 1)
                {
                    y1 = i - 1;
                    y2 = i + 1;
                }
                else
                {
                    y1 = i - 2;
                    y2 = i - 1;
                }

                if (j % 3 == 0)
                {
                    x1 = j + 1;
                    x2 = j + 2;
                }
                else if (j % 3 == 1)
                {
                    x1 = j - 1;
                    x2 = j + 1;
                }
                else
                {
                    x1 = j - 2;
                    x2 = j - 1;
                }

                if (
                    (board[y1][x1] == board[i][j]) ||
                    (board[y1][x2] == board[i][j]) ||
                    (board[y2][x1] == board[i][j]) ||
                    (board[y2][x2] == board[i][j]))
                    return false;
            }
        }
        return true;
    }

    /**
     * @brief Hash Sets
     * @details Track seen digits in rows, columns, and 3×3 boxes using hash sets
     * @complexity: Time: O(1), Space: O(1)
     */
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                int boxIndex = (i / 3) * 3 + (j / 3);
                int val = board[i][j];
                if (rows[i].count(val) || cols[j].count(val) || boxes[boxIndex].count(val))
                    return false;

                rows[i].insert(val);
                cols[j].insert(val);
                boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};