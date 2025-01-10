#include <vector>
#include <iostream>
#include <algorithm>

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long val = 0) : val(val), left(nullptr), right(nullptr) {}
};

void rec(TreeNode* root, std::vector<long long> nodeVals, long long currSum, int& K) {
    
    if (!root) return;
    nodeVals.push_back(root->val);
    currSum += root->val;
    if (!root->left && !root->right) {
        if (currSum == K) {
            for (const auto& val: nodeVals) std::cout << val << ' ';
            std::cout << '\n';
        }
        return;
    }
    rec(root->left, nodeVals, currSum, K);
    rec(root->right, nodeVals, currSum, K);
}


int main() {
    
    int K; std::cin >> K;
    int N; std::cin >> N;
    std::vector<TreeNode*> nodes(N);
    for (int i = 0; i < N; i++) {
        long long temp;
        std::cin >> temp;
        nodes[i] = new TreeNode(temp);
    }
    int E; std::cin >> E;
    for (int i = 0; i < E; i++) {
        char direction; int parent, child;
        std::cin >> direction >> parent >> child;
        if (direction == 'L') nodes[parent]->left = nodes[child];
        else nodes[parent]->right = nodes[child];
    }

    rec(nodes[0], {}, 0, K);
}
