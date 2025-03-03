/**
 * @brief First/Only Solution
 * -- m4 3aref complexity
 * -- For each subtree, compare the whole part
 */
class Solution
{
public:
    bool compareTree(TreeNode *sub1, TreeNode *sub2)
    {
        if (!sub1 && !sub2)
            return true;
        if (sub1 && sub2 && sub1->val == sub2->val)
            return compareTree(sub1->left, sub2->left) && compareTree(sub1->right, sub2->right);
        return false;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!subRoot)
            return true;
        if (!root)
            return false;
        if (compareTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};