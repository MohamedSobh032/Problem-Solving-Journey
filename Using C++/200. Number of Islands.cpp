/**
 * @brief First Solution
 * -- Time Complexity: O(n*m)
 * -- Space Complexity: O(n*m)
 * -- Iterates over the grid and for each cell that is not visited and is a land
 *    it performs a DFS to mark all the cells that are connected to it
 */
class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int x, int y, const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& isVisited) {

        if (!((0 <= x && x < grid.size()) && (0 <= y && y < grid[0].size())) || grid[x][y] == '0' || isVisited[x][y]) return;
        isVisited[x][y] = true;
        for (const auto& dir: dirs) dfs(x + dir.first, y + dir.second, grid, isVisited);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int counter = 0;
        std::vector<std::vector<bool>> isVisited(grid.size(), std::vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (isVisited[i][j] || grid[i][j] == '0') continue;
                counter++;
                dfs(i, j, grid, isVisited);
                isVisited[i][j] = true;
            }
        }
        return counter;
    }
};

/**
 * @brief First Solution
 * -- Time Complexity: O(n*m)
 * -- Space Complexity: O(n*m)
 * -- Same as above, but using BFS instead of DFS
 */
class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void bfs(int x, int y, const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& isVisited) {

        std::queue<std::pair<int, int>> q;
        q.push({x, y});
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (const auto& dir: dirs) {
                int new_r = row + dir.first;
                int new_c = col + dir.second;
                if (!((0 <= new_r && new_r < grid.size()) && (0 <= new_c && new_c < grid[0].size()))) continue;
                if (grid[new_r][new_c] == '0') continue;
                if (isVisited[new_r][new_c]) continue;
                q.push({new_r, new_c});
                isVisited[new_r][new_c] = true;
            }
        }  
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int counter = 0;
        std::vector<std::vector<bool>> isVisited(grid.size(), std::vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (isVisited[i][j]) continue;
                if (grid[i][j] == '0') { isVisited[i][j] = true; continue; }
                counter++;
                bfs(i, j, grid, isVisited);
            }
        }
        return counter;
    }
};