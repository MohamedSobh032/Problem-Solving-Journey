#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    /**
     * @brief iterative BFS
     * @details simulates rotting oranges level by level using a growing vector to track infected cells
     * @complexity: Time: O(n * m), Space: O(n * m)
     */
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int counter = 0;
        vector<pair<int, int>> rots;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    rots.push_back({i, j});

        bool flag = true;
        while (flag)
        {
            flag = false;
            int len = rots.size();
            for (int i = 0; i < len; i++)
            {
                for (const pair<int, int> &dir : dirs)
                {
                    int x = rots[i].first + dir.first, y = rots[i].second + dir.second;
                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    flag = true;
                    rots.push_back({x, y});
                }
            }
            if (flag)
                counter++;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    return -1;
        return counter;
    }

    /**
     * @brief BFS
     * @details uses level-order traversal to spread rotting oranges and count minutes
     * @complexity: Time: O(n * m), Space: O(n * m)
     */
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, minutes = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;

        while (!q.empty() && fresh > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [r, c] = q.front();
                q.pop();
                for (auto &[dx, dy] : dirs)
                {
                    int x = r + dx, y = c + dy;
                    if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != 1)
                        continue;
                    grid[x][y] = 2;
                    q.push({x, y});
                    fresh--;
                }
            }
            minutes++;
        }

        return fresh > 0 ? -1 : minutes;
    }
};