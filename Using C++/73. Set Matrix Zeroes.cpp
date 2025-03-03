/**
 * @brief First Solution
 * --> Time Complexity: O(n*m)
 * --> Space Complexity: O(n*m)
 * --> Iterates on the matrix and if a zero is found, sets the entire row and column to zero
 */
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int N = matrix.size();
        int M = matrix[0].size();
        std::vector<std::vector<int>> originally = matrix;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (originally[i][j] == 0)
                {
                    for (int k = 0; k < M; k++)
                        matrix[i][k] = 0;
                    for (int k = 0; k < N; k++)
                        matrix[k][j] = 0;
                }
            }
        }
    }
};

/**
 * @brief Second Solution
 * --> Time Complexity: O(n*m)
 * --> Space Complexity: O(n+m)
 * --> Uses an extra row and column to store the information about the rows and columns that need to be set to zero
 */
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int N = matrix.size();
        int M = matrix[0].size();
        matrix.insert(matrix.begin(), std::vector<int>(M, 0));
        for (auto &row : matrix)
            row.insert(row.begin(), 0);

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < M + 1; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 1;
                    matrix[i][0] = 1;
                }
            }
        }

        // remove rows
        for (int i = 1; i < N + 1; i++)
            if (matrix[i][0] == 1)
                for (int j = 1; j < M + 1; j++)
                    matrix[i][j] = 0;

        // remove columns
        for (int i = 1; i < M + 1; i++)
            if (matrix[0][i] == 1)
                for (int j = 1; j < N + 1; j++)
                    matrix[j][i] = 0;

        matrix.erase(matrix.begin());
        for (auto &row : matrix)
            if (!row.empty())
                row.erase(row.begin());
    }
};

/**
 * @brief Third Solution
 * --> Time Complexity: O(n*m)
 * --> Space Complexity: O(1)
 * --> Uses the first row and column to store the information about the rows and columns that need to be set to zero
 */
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        int N = matrix.size();
        int M = matrix[0].size();
        bool row_zero = false;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if (i > 0)
                        matrix[i][0] = 0;
                    else
                        row_zero = true;
                }
            }
        }

        for (int i = 1; i < N; i++)
            for (int j = 1; j < M; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;

        if (matrix[0][0] == 0)
            for (int j = 0; j < N; j++)
                matrix[j][0] = 0;

        if (row_zero)
            for (int j = 0; j < M; j++)
                matrix[0][j] = 0;
    }
};