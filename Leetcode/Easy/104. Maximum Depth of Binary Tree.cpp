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
public:
    /**
     * @brief DFS traversal
     * @details recursively computes the height of the left and right subtrees, and returns the greater of the two, plus one
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` means number of nodes, `h` means height of the tree
     */
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    /**
     * @brief BFS traversal
     * @details level-order traversal by pushing nodes into a queue level by level and incrementing the depth each level.
     * @complexity: Time: O(n), Space: O(n)
     */
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int pop_times = q.size();
            for (int i = 0; i < pop_times; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return depth;
    }
};
