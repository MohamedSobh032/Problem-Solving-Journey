#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void dfs(TreeNode *root, vector<vector<int>> &lo, int n)
    {
        if (!root)
            return;
        if (lo.size() == n)
            lo.emplace_back();

        lo[n].push_back(root->val);
        dfs(root->left, lo, n + 1);
        dfs(root->right, lo, n + 1);
    }

public:
    /**
     * @brief Depth-first search (Recursive Level Order)
     * @details builds the level order by tracking depth in a recursive DFS traversal
     * @complexity: Time: O(n), Space: O(h)
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> lo;
        dfs(root, lo, 0);
        return lo;
    }

    /**
     * @brief Breadth-first search (Queue Level Order)
     * @details uses a queue to traverse nodes level by level and track their depth
     * @complexity: Time: O(n), Space: O(n)
     */
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> lo;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, 0);
        while (!q.empty())
        {
            auto [node, depth] = q.front();
            q.pop();
            if (lo.size() == depth)
                lo.emplace_back();
            lo[depth].push_back(node->val);
            if (node->left)
                q.emplace(node->left, depth + 1);
            if (node->right)
                q.emplace(node->right, depth + 1);
        }
        return lo;
    }
};