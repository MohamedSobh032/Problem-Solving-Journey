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
    TreeNode(long long data = 0) : val(data), left(nullptr), right(nullptr) {}
};


long long getDiff(TreeNode* root, int& R, long long& count) {
    
    // base-case
    if (!root)
        return 0;
    // recursion
    long long leftSum = getDiff(root->left, R, count);
    long long rightSum = getDiff(root->right, R, count);
    // back-tracking
    if (abs(leftSum - rightSum) <= R)
        count++;
    return root->val + leftSum + rightSum;
}


int main() {
    
    // INPUT
    int N, R, E; std::cin >> N >> R;
    vector<TreeNode*> nodes(N);
    for (int i = 0; i < N; i++) {
        long long temp = 0;
        std::cin >> temp;
        nodes[i] = new TreeNode(temp);
    } 
    std::cin >> E;
    for (int i = 0; i < E; i++) {
        char direction;
        int parent, child;
        std::cin >> direction >> parent >> child;
        if (direction == 'L')
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    long long count = 0;
    getDiff(nodes[0], R, count);
    cout << count;
    
    return 0;
}
