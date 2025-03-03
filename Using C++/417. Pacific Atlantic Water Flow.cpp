/**
 * @brief First Solution
 * -- Time Complexity: O(n * m * 4 ^ (n * m))
 * -- Space Complexity: O(n * m)
 * -- For each cell, expands to all the cells that can be reached from it and marks the cells that can be reached from the ocean.
 */
class Solution
{
public:
    std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    void dfs(const std::vector<std::vector<int>> &heights, std::vector<std::vector<bool>> &isVisited,
             int x, int y, std::pair<bool, bool> &canReach)
    {
        isVisited[x][y] = true;
        if (x == 0 || y == 0)
            canReach.first = true;
        if (x == n - 1 || y == m - 1)
            canReach.second = true;

        for (const auto &dir : dirs)
        {
            if (canReach.first && canReach.second)
                return;
            int nx = x + dir.first, ny = y + dir.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || isVisited[nx][ny] || heights[x][y] < heights[nx][ny])
                continue;
            dfs(heights, isVisited, nx, ny, canReach);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        std::vector<std::vector<int>> ret;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                std::pair<bool, bool> canReach = std::make_pair(false, false);
                std::vector<std::vector<bool>> isVisited(n, std::vector<bool>(m, false));
                dfs(heights, isVisited, x, y, canReach);
                if (canReach.first && canReach.second)
                    ret.push_back({x, y});
            }
        }
        return ret;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n * m)
 * -- Space Complexity: O(n * m)
 * -- Expands from the entry points of the ocean and marks the cells that can be reached from the ocean.
 *    Then, it checks the cells that can be reached from both oceans.
 */
class Solution
{
public:
    std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;

    void dfs(const std::vector<std::vector<int>> &heights, std::vector<std::vector<bool>> &visited, int x, int y)
    {
        if (visited[x][y])
            return;

        visited[x][y] = true;
        for (const auto &dir : dirs)
        {
            int nx = x + dir.first, ny = y + dir.second;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || heights[x][y] > heights[nx][ny])
                continue;
            dfs(heights, visited, nx, ny);
        }
    }

    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        std::vector<std::vector<int>> result;
        std::vector<std::vector<bool>> reach_pacific(n, std::vector<bool>(m, false));
        std::vector<std::vector<bool>> reach_atlantic(n, std::vector<bool>(m, false));

        for (int i = 0; i < n; i++)
            dfs(heights, reach_pacific, i, 0);
        for (int i = 0; i < m; i++)
            dfs(heights, reach_pacific, 0, i);
        for (int i = n - 1; i >= 0; i--)
            dfs(heights, reach_atlantic, i, m - 1);
        for (int i = m - 1; i >= 0; i--)
            dfs(heights, reach_atlantic, n - 1, i);

        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (reach_pacific[x][y] && reach_atlantic[x][y])
                    result.push_back({x, y});

        return result;
    }
};
