#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long

struct TreeNode {
    ll val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(ll val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr) : val(val), left(left), right(right) {}
};


void rec(TreeNode* root, int index, std::vector<ll>& level_sums) {

    if (!root) return;
    if (static_cast<int>(level_sums.size()) <= index) level_sums.push_back(root->val);
    else level_sums[index] += root->val;
    rec(root->left, index + 1, level_sums);
    rec(root->right, index + 1, level_sums);
}


int main() {

    // input
    int N; std::cin >> N;
    std::vector<TreeNode*> nodes(N);
    for (int i = 0; i < N; i++) {
        ll temp; std::cin >> temp;
        nodes[i] = new TreeNode(temp);
    }
    
    int E; std::cin >> E;
    for (int i = 0; i < E; i++) {
        char dir; int p, c; std::cin >> dir >> p >> c;
        if (dir == 'R') nodes[p]->right = nodes[c];
        else nodes[p]->left = nodes[c];
    }

    std::vector<ll> level_sums;
    rec(nodes[0], 0, level_sums);
    std::cout << level_sums[level_sums.size() - 1];
}
