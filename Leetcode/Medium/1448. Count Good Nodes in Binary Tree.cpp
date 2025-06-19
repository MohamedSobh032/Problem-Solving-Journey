#include <algorithm>
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
    void dfs(TreeNode *root, int max_within_route, int &count)
    {
        if (!root)
            return;
        count += root->val >= max_within_route;
        max_within_route = max(root->val, max_within_route);
        dfs(root->left, max_within_route, count);
        dfs(root->right, max_within_route, count);
    }

public:
    /**
     * @brief Depth-first search
     * @details uses recursion to count nodes greater than or equal to all ancestors on the path
     * @complexity: Time: O(n), Space: O(h) (recursive stack)
     */
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        dfs(root, INT_MIN, count);
        return count;
    }

    /**
     * @brief Breadth-first search
     * @details uses a queue to traverse level by level and compare values with max so far on path
     * @complexity: Time: O(n), Space: O(n)
     */
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        queue<pair<TreeNode *, int>> q;
        q.emplace(root, INT_MIN);
        while (!q.empty())
        {
            auto [node, val] = q.front();
            q.pop();
            if (!node)
                continue;

            count += node->val >= val;
            val = max(node->val, val);
            q.emplace(node->left, val);
            q.emplace(node->right, val);
        }
        return count;
    }
};
