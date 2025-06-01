#include <algorithm>
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
    int dfs(TreeNode *root, bool &prune)
    {
        if (prune || !root)
            return 0;

        int left_height = dfs(root->left, prune);
        int right_height = dfs(root->right, prune);
        if (!prune)
            prune = abs(left_height - right_height) >= 2;
        return max(left_height, right_height) + 1;
    }

    pair<bool, int> dfs(TreeNode *node)
    {
        if (!node)
            return {true, 0};

        auto [left_balance, left_height] = dfs(node->left);
        auto [right_balance, right_height] = dfs(node->right);
        return {left_balance && right_balance && abs(left_height - right_height) <= 1, 1 + max(left_balance, right_balance)};
    }

public:
    /**
     * @brief DFS traversal with pruning
     * @details recursively computes the height of left and right subtrees. with boolean flag passed by reference used as circuit breaker
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` means number of nodes, `h` means height of the tree
     */
    bool isBalanced(TreeNode *root)
    {
        bool prune = false;
        dfs(root, prune);
        return !prune;
    }

    /**
     * @brief DFS traversal
     * @details same as above but returns both the height and the balanced in a structure
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` means number of nodes, `h` means height of the tree
     */
    bool isBalanced(TreeNode *root)
    {
        return dfs(root).first;
    }
};