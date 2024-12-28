/**
 * @brief First Solution
 * --> Time Complexity: O(n^2)
 * --> Space Complexity: O(1)
 * --> Transpose and then reverse vertical mirror
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int N = matrix.size();
        // TRANSPOSE
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                std::swap(matrix[i][j], matrix[j][i]);
        // REVERSE VERTICAL MIRROR
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N / 2; j++)
                std::swap(matrix[i][j], matrix[i][N - j - 1]);
    }
};