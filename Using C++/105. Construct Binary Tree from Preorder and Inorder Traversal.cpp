/**
 * @brief First/Only Solution
 * -- m4 3aref agib complexity
 * -- preorder gets the root, inorder gets the left and right
 */
class Solution
{
public:
    TreeNode *rec(vector<int> &preorder, vector<int> &inorder,
                  int preleft, int preright, int inleft, int inright,
                  unordered_map<int, int> &nmap)
    {
        // base case
        if (preleft > preright || inleft > inright)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preleft]);
        int index = nmap[preorder[preleft]];
        int numbers = index - inleft;
        root->left = rec(preorder, inorder,
                         preleft + 1, preleft + numbers,
                         inleft, index - 1,
                         nmap);
        root->right = rec(preorder, inorder,
                          preleft + numbers + 1, preright,
                          index + 1, inright,
                          nmap);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> nmap;
        for (size_t i = 0; i < inorder.size(); i++)
            nmap[inorder[i]] = i;
        return rec(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, nmap);
    }
};