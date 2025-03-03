/**
 * @brief First/Only Solution
 * -- m4 3aref agib complexity
 * -- m4 mhtaga 4ar7
 */
class Solution
{
public:
    void rec(TreeNode *root, bool &valid, long minimum, long maximum)
    {
        // base case
        if (!root)
            return;
        if (root->val <= minimum || root->val >= maximum)
        {
            valid = false;
            return;
        }

        rec(root->left, valid, minimum, root->val);
        rec(root->right, valid, root->val, maximum);
    }

    bool isValidBST(TreeNode *root)
    {
        bool valid = true;
        rec(root, valid, LONG_MIN, LONG_MAX);
        return valid;
    }
};