#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(val), left(left), right(right) {}
};

bool dfs(TreeNode* root, long long& count) {
    
    if (!root) return true;
    bool leftIsEgo = true, rightIsEgo = true;
    
    if (root->left)  leftIsEgo = dfs(root->left, count);
    if (root->right) rightIsEgo = dfs(root->right, count);

    if ((root->left && root->val != root->left->val) || (root->right && root->val != root->right->val))
        return false;

    if (leftIsEgo && rightIsEgo) {
        count++;
        return true;
    }
    
    return false;
}

int main() {
    
    long long N, E; std::cin >> N >> E;
    std::vector<TreeNode*> nodes(N);
    for (long long i = 0; i < N; i++) {
        long long temp; std::cin >> temp;
        nodes[i] = new TreeNode(temp);
    }
    
    for (long long i = 0; i < E; i++) {
        char dir; long long p, c; std::cin >> dir >> p >> c; p--; c--;
        if (dir == 'L')
            nodes[p]->left = nodes[c];
        else
            nodes[p]->right = nodes[c];
    }
    
    long long count = 0;
    dfs(nodes[0], count);
    std::cout << count;
}
