/**
 * @brief First Solution
 * ---> O(n + m)
 * ---> Traverse through each position and add them
 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return nullptr;
        if (!root2)
            return root1;
        if (!root1)
            return root2;

        TreeNode *root = new TreeNode();
        root->val = root1->val + root2->val;
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }
};

/**
 * @brief Second Solution
 * ---> O(n + m)
 * ---> Traverse through each position and add them
 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root2)
            return root1;
        if (!root1)
            return root2;

        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};