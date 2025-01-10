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

    if (!root) return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void buildLevels(node* curr, std::vector<std::vector<int>>& levels, std::vector<int>& sums, int index) {
    
    // Base-case
    if (!curr) return;

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
    for (int i = 0; i < N; i++) std::cin >> values[i];
    int E; std::cin >> E;
    
    std::vector<node*> nodes(N);
    for (int i = 0; i < N; i++) nodes[i] = new node(values[i]);
    
    for (int i = 0; i < E; i++) {
        char direction;
        int parent, child;
        std::cin >> direction >> parent >> child;
        if (direction == 'L') nodes[parent]->left = nodes[child];
        else nodes[parent]->right = nodes[child];
    }
    
    int height = getHeight(nodes[0]);
    // Build levels with height inside
    std::vector<std::vector<int>> levels(height);
    std::vector<int> sums(height, 0);
    buildLevels(nodes[0], levels, sums, 0);
    
    // Get K
    int L = levels[0][0] % height, K = INT_MAX;
    for (int i = 0; i < (int)levels[L].size(); i++) K = std::min(K, levels[L][i]);
    K %= height;
    if (K == 0) K = 1;
    
    // Iterate, get sum, and append
    std::string s("");
    for (int i = 0; i < height; i += K) s += std::to_string(sums[i]);
    std::cout << s;
}