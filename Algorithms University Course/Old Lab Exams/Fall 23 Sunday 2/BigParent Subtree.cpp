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

pair<bool, long long> dfs(TreeNode* root, long long& maximum) {
    
    // nullptr case
    if (!root) return std::make_pair(true, 0);
    
    std::pair<bool, long long> fp = dfs(root->left, maximum);
    std::pair<bool, long long> sp = dfs(root->right, maximum);
    
    if (fp.first && sp.first && !((root->left && root->val < root->left->val) || (root->right && root->val < root->right->val))) {
        maximum = std::max(maximum, root->val + fp.second + sp.second);
        return std::make_pair(true, root->val + fp.second + sp.second);
    } else return std::make_pair(false, root->val);
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
    
    long long maximum = 0;
    dfs(nodes[0], maximum);
    cout << maximum;
}
