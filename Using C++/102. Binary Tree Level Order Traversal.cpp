/**
 * @brief First Solution
 * -- M4 3aref agib complexity
 * -- append with recursion by incrementing index
 */
class Solution
{
public:
    void buildLevels(TreeNode *root, int index, vector<vector<int>> &levels)
    {
        if (!root)
            return;
        if (index == (int)levels.size())
            levels.push_back({});
    
        levels[index].push_back(root->val);
        buildLevels(root->left, index + 1, levels);
        buildLevels(root->right, index + 1, levels);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> levels;
        buildLevels(root, 0, levels);
        return levels;
    }
};