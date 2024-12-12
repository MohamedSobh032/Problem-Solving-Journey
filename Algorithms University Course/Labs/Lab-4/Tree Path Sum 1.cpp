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
    TreeNode(long long val = 0) : val(val), left(nullptr), right(nullptr) {}
};

void rec(TreeNode* root, vector<long long> nodeVals, long long currSum, int& K, vector<vector<long long>>& vect) {
    
    // Base-case
    if (!root)
        return;
    // add the value and increment sum
    nodeVals.push_back(root->val);
    currSum += root->val;
    if (!root->left && !root->right) {
        if (currSum == K) // You can print here instead of pushing in a vector, the vect will not be needed then
            vect.push_back(nodeVals);
        return;
    }
    // recursive
    rec(root->left, nodeVals, currSum, K, vect);
    rec(root->right, nodeVals, currSum, K, vect);
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
        char direction;
        int parent, child;
        std::cin >> direction >> parent >> child;
        if (direction == 'L')
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    
    // Get answer in vect
    vector<vector<long long>> vect;
    rec(nodes[0], {}, 0, K, vect);
    
    // Printing
    for (size_t i = 0; i < vect.size(); i++) {
        for (size_t j = 0; j < vect[i].size(); j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
