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
     * @details compares structure and values of both trees recursively
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` = number of nodes, `h` = height of the tree
     */
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!(p && q) || (p->val != q->val))
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};