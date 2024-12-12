/*
An encryption key is hidden in a binary tree. The key is the concatenation of sums of selected levels of the tree. The selected levels start at level 0 (root level) and continues down the tree by K steps every time. For a tree with 9 levels, if K=3, the selected levels will be 0, 3, 6. K is the minimum value of the Lth level % the tree height. L is the value of the root % the tree height. You are allowed to use unordered_map and unordered_set if needed. If K is 0, set to 1 instead.

Input Format
The first line will contain the number of nodes in the tree N.
The following N numbers will contain the data in each node.
The next line will contain the number of edges in the tree E.
The following E lines will contain 3 values:
L or R to represent if this is a left or right child
Index of the parent.
Index of the child.

Constraints
N is between 1 and 10^6
Node 0 is always the root
Root is in level 0
Node values are between 1 and 10^4

Output Format
The concatenation of the sums in one line.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

struct node {
    int data;
    node* left;
    node* right;
    node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

int getHeight(node* root) {
    if (root == nullptr) return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void buildLevels(node* curr, std::vector<std::vector<int>>& levels, std::vector<int>& sums, int index) {
    
    // base case
    if (curr == nullptr)
        return;

    // append new data
    levels[index].push_back(curr->data);
    sums[index] += curr->data;
    
    // recursion
    buildLevels(curr->left, levels, sums, index + 1);
    buildLevels(curr->right, levels, sums, index + 1);
}


int main() {
    
    // Input N number of nodes, value of each node, and E edges
    int N; std::cin >> N;
    std::vector<int> values(N);
    for (int i = 0; i < N; i++)
        std::cin >> values[i];
    int E; std::cin >> E;
    
    std::vector<node*> nodes(N);
    for (int i = 0; i < N; i++)
        nodes[i] = new node(values[i]);
    
    for (int i = 0; i < E; i++) {
        char direction;
        int parent, child;
        std::cin >> direction >> parent >> child;
        if (direction == 'L')
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    
    int height = getHeight(nodes[0]);
    
    // Build levels with height inside
    std::vector<std::vector<int>> levels(height);
    std::vector<int> sums(height, 0);
    buildLevels(nodes[0], levels, sums, 0);
    
    // Get K
    int L = levels[0][0] % height;
    int K = INT_MAX;
    for (int i = 0; i < (int)levels[L].size(); i++)
        K = std::min(K, levels[L][i]);
    K %= height;
    if (K == 0) K = 1;
    
    // Iterate, get sum, and append
    std::string s = "";
    for (int i = 0; i < height; i += K)
        s += std::to_string(sums[i]);
    std::cout << s;
    
    return 0;
}