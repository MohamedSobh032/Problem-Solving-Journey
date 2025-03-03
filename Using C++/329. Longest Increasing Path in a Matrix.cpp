/**
 * @brief First Solution
 * -- Time Complexity: O(4^(nm))
 * -- Space Complexity: O(nm)
 * -- Brute-force Solution
 */
class Solution
{
public:
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void rec(const std::vector<std::vector<int>> &matrix, const int &n, const int &m,
             int last_elem, int x, int y, int curr_len, int &max_len)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || matrix[x][y] <= last_elem)
            return;

        curr_len++;
        max_len = std::max(max_len, curr_len);
        for (const auto dir : dirs)
            rec(matrix, n, m, matrix[x][y], x + dir.first, y + dir.second, curr_len, max_len);
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int max_len = INT_MIN;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                rec(matrix, n, m, -1, i, j, 0, max_len);
        return max_len;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(nm)
 * -- Top-down DP approach
 */
class Solution
{
public:
    std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rec(const std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &dp,
            const int &n, const int &m, int x, int y)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        int max_len = 1;
        for (const auto &dir : dirs)
        {
            int newx = x + dir.first, newy = y + dir.second;
            if (newx < 0 || newx >= n || newy < 0 || newy >= m || matrix[x][y] >= matrix[newx][newy])
                continue;
            max_len = std::max(max_len, 1 + rec(matrix, dp, n, m, newx, newy));
        }
        return dp[x][y] = max_len;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
        int max_len = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                max_len = std::max(max_len, rec(matrix, dp, n, m, i, j));
        return max_len;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(nm)
 * -- Space Complexity: O(nm)
 * -- Bottom-up DP approach using topological sort approach
 */
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 1: Compute indegrees for each cell
        std::vector<std::vector<int>> indegree(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (const auto &dir : dirs)
                {
                    int newx = i + dir.first, newy = j + dir.second;
                    if (newx >= 0 && newx < n && newy >= 0 && newy < m && matrix[i][j] < matrix[newx][newy])
                        indegree[newx][newy]++;
                }
            }
        }

        // Step 2: Add cells with indegree 0 to the queue
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (indegree[i][j] == 0)
                    q.push({i, j});

        // Step 3: Process the cells in topological order
        int max_len = 0;
        while (!q.empty())
        {
            int size = q.size();
            max_len++;
            for (int i = 0; i < size; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for (const auto &dir : dirs)
                {
                    int newx = x + dir.first, newy = y + dir.second;
                    if (newx >= 0 && newx < n && newy >= 0 && newy < m && matrix[x][y] < matrix[newx][newy])
                    {
                        indegree[newx][newy]--;
                        if (indegree[newx][newy] == 0)
                            q.push({newx, newy});
                    }
                }
            }
        }

        return max_len;
    }
};