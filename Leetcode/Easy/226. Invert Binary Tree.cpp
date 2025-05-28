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
     * @details swaps the left and right children of the current node, then recurisvely inverts the sub-tree
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` means number of nodes, `h` means height of the tree
     */
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    /**
     * @brief DFS traversal
     * @details recurisvely inverts the the left and right sub-trees, then swaps them
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` means number of nodes, `h` means height of the tree
     */
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    }
};