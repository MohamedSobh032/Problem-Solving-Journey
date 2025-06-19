#include <vector>
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
private:
    void dfs(TreeNode *root, vector<int> &rv, int depth)
    {
        if (!root)
            return;
        if (depth == rv.size())
            rv.emplace_back();
        rv[depth] = root->val;
        dfs(root->left, rv, depth + 1);
        dfs(root->right, rv, depth + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> rv;
        dfs(root, rv, 0);
        return rv;
    }
};