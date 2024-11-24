

/**
 * @brief First Solution
 * -- m4 3aref agib complexity
 * -- Recursive
 */
class Solution {
public:
    int maximum = INT_MIN;
    void my_maxDepth(TreeNode* root, int index) {   
        if (!root) {
            maximum = max(maximum, index-1);
            return;
        }
        my_maxDepth(root->left, index+1);
        my_maxDepth(root->right, index+1);
    }
    int maxDepth(TreeNode* root) {
        my_maxDepth(root, 1);
        return maximum;
    }
};

/**
 * @brief Second Solution
 * -- m4 3aref agib complexity
 * -- Recursive
 * -- Best solution
 */
class Solution {
public:
    int maxDepth(TreeNode* root) { 
        if (!root)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return ((left > right) ? left : right) + 1; 
    }
};


