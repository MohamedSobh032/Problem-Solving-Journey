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
public:
    int maximum_diameter = 0;

    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        maximum_diameter = max(maximum_diameter, left_height + right_height);
        return max(left_height, right_height) + 1;
    }

    /**
     * @brief DFS traversal
     * @details calculates both the max height and the max diameter for each node, return the max height and saves the max diameter in a global variable
     * @complexity: Time: O(n), Space: O(h)
     * @note `n` means number of nodes, `h` means height of the tree
     */
    int diameterOfBinaryTree(TreeNode *root)
    {
        int current_max = maxDepth(root->left) + maxDepth(root->right);
        return max(current_max, maximum_diameter);
    }
};