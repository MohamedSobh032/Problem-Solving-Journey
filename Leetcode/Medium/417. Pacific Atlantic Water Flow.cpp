#include <vector>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs_func(const vector<vector<int>> &heights, int r, int c, vector<vector<bool>> &dfs)
    {
        for (const auto &pair : dirs)
        {
            int new_r = r + pair.first;
            int new_c = c + pair.second;

            if (new_r >= heights.size() || new_c >= heights[0].size() || new_r < 0 || new_c < 0 || dfs[new_r][new_c])
                continue;

            if (heights[new_r][new_c] >= heights[r][c])
            {
                dfs[new_r][new_c] = true;
                dfs_func(heights, new_r, new_c, dfs);
            }
        }
    }

public:
    /**
     * @brief DFS traversal
     * @details finds all cells reachable by both Pacific and Atlantic oceans, then combine both
     * @complexity: Time: O(m * n), Space: O(m * n) (visited matrices + recursion)
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> pacific(r, vector<bool>(c, false)), atlantic(r, vector<bool>(c, false));

        for (int i = 0; i < r; i++)
        {
            pacific[i][0] = true;
            atlantic[i][c - 1] = true;
        }
        for (int i = 0; i < c; i++)
        {
            pacific[0][i] = true;
            atlantic[r - 1][i] = true;
        }

        for (int i = 0; i < r; i++)
        {
            dfs_func(heights, i, 0, pacific);
            dfs_func(heights, i, c - 1, atlantic);
        }
        for (int i = 0; i < c; i++)
        {
            dfs_func(heights, 0, i, pacific);
            dfs_func(heights, r - 1, i, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
        return ans;
    }
};
