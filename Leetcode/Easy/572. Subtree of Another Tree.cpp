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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!(p && q) || (p->val != q->val))
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    /**
     * @brief DFS traversal
     * @details checks if subRoot is a subtree of root by comparing each node with subRoot using isSameTree
     * @complexity: Time: O(m * n), Space: O(h)
     * @note `n` means number of nodes in subRoot, `m` means number of nodes in root, `h` means the height of the root
     */
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;
        if (root->val == subRoot->val)
        {
            if (isSameTree(root, subRoot))
                return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};