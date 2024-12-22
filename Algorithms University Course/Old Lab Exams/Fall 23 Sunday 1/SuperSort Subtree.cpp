#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : data(val), left(left), right(right) {}
};

bool isBST(TreeNode* subroot, int minval, int maxval) {
    
    if (!subroot) return true;
    if (subroot->data >= maxval || subroot->data <= minval) return false;
    return isBST(subroot->left, minval, subroot->data) && isBST(subroot->right, subroot->data, maxval);
}

int treeSize(TreeNode* subroot) {
    
    if (!subroot) return 0;
    return 1 + treeSize(subroot->right) + treeSize(subroot->left);
}

void findmax(TreeNode* subroot, int& maxsize) {
    
    if (!subroot) return;

    int leftsize = treeSize(subroot->left);
    int rightsize = treeSize(subroot->right);

    if (isBST(subroot, INT_MIN, INT_MAX))
        maxsize = max(maxsize, leftsize + rightsize + 1);

    findmax(subroot->left, maxsize);
    findmax(subroot->right, maxsize);
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
        if (dir == 'L') nodes[p]->left = nodes[c];
        else nodes[p]->right = nodes[c];
    }
    
    int maximum = 0;
    findmax(nodes[0], maximum);
    cout << maximum;
}
