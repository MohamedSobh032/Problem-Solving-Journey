/**
 * @brief First Solution
 * -- O(nlogn)
 * -- get all elements, sort them and get by index
 */
class Solution
{
public:
    void getvec(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;
        vec.push_back(root->val);
        getvec(root->left, vec);
        getvec(root->right, vec);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> l;
        getvec(root, l);
        std::sort(l.begin(), l.end());
        return l[k - 1];
    }
};

/**
 * @brief Second Solution
 * -- O(H), H = height of the tree
 * -- Inorder traversal recursion
 */
class Solution
{
public:
    void rec(TreeNode *root, int &k, int &ret)
    {
        // base-case
        if (!root)
            return;
            
        // recursion with inorder traversal
        rec(root->left, k, ret);
        k--;
        if (k == 0)
        {
            ret = root->val;
            return;
        }
        rec(root->right, k, ret);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ret = 0;
        rec(root, k, ret);
        return ret;
    }
};