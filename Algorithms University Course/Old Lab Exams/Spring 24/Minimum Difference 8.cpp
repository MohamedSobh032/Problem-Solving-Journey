#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int val) {
    
    // BASECASE
    if (!root)
        return new TreeNode(val);

    // CONSTRUCTION
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

TreeNode* buildBSTFromPreorder(std::vector<int>& preorder) {
    
    TreeNode* root = nullptr;
    for (const int& val : preorder)
        root = insertBST(root, val);
    return root;
}

void postorderTraversal(TreeNode* root) {
    
    // BASECASE
    if (!root)
        return;
    
    // POSTORDER TRAVERSAL
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->val << std::endl;
}

void inorderTraversal(TreeNode* root, std::vector<int>& inorder) {
    
    // BASECASE
    if (!root)
        return;
    
    // INORDER TRAVERSAL
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

int main() {
    
    // INPUT
    int n; std::cin >> n;
    std::vector<int> preorder(n);
    for (int i = 0; i < n; i++)
        std::cin >> preorder[i];

    // TREE CONSTRUCTION
    TreeNode* root = buildBSTFromPreorder(preorder);
    
    // PRINT POST-ORDER
    postorderTraversal(root);

    // FIND ABSOLUTE MINIMUM INORDER
    std::vector<int> inorder;
    inorderTraversal(root, inorder);
    int minDiff = INT_MAX;
    for (int i = 1; i < (int)inorder.size(); i++)
        minDiff = std::min(minDiff, inorder[i] - inorder[i-1]);
    std::cout << minDiff;
}
