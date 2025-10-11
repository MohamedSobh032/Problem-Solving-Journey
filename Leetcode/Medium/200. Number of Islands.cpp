#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(const vector<vector<char>> &grid, vector<vector<bool>> &isVisited, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || isVisited[i][j])
            return;
        isVisited[i][j] = true;
        if (grid[i][j] == '0')
            return;

        dfs(grid, isVisited, i + 1, j);
        dfs(grid, isVisited, i - 1, j);
        dfs(grid, isVisited, i, j + 1);
        dfs(grid, isVisited, i, j - 1);
    }

public:
    /**
     * @brief Count connected components using Depth-first search (DFS)
     * @details iterates through the grid and counts disconnected land regions using DFS
     * @complexity: Time: O(n * m), Space: O(n * m)
     */
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0, n = grid.size(), m = grid[0].size();
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isVisited[i][j])
                    continue;
                if (grid[i][j] == '0')
                {
                    isVisited[i][j] = true;
                    continue;
                }
                count++;
                dfs(grid, isVisited, i, j);
            }
        }
        return count;
    }
};
