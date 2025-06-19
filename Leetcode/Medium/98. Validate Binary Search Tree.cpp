#include <climits>
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
     * @brief Recursive in-range check
     * @details ensures each node is within a valid range (min, max) recursively down the tree
     * @complexity: Time: O(n), Space: O(h) (recursive stack)
     */
    bool isValidBST(TreeNode *root, long minimum = LONG_MIN, long maximum = LONG_MAX)
    {
        if (!root)
            return true;
        if (minimum >= root->val || root->val >= maximum)
            return false;
        return isValidBST(root->left, minimum, root->val) &&
               isValidBST(root->right, root->val, maximum);
    }
};