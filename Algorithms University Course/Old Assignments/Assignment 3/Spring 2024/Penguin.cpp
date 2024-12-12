#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

node* constructTree(std::vector<int>& data, int start, int end) {
    
    // base case
    if (start > end)
        return nullptr;
    // get index
    int mid = start + (end - start) / 2;
    node* n = new node(data[mid]);
    // construct left and right subtree
    n->left = constructTree(data, start, mid - 1);
    n->right = constructTree(data, mid + 1, end);
    // return the root of the subtree
    return n;
}

void constructMap(node* root, vector<vector<int>>& levels, int index) {
    
    if (!root)
        return;
    if (levels.size() == (size_t)index)
        levels.push_back({});
    levels[index].push_back(root->data);
    
    constructMap(root->left, levels, index + 1);
    constructMap(root->right, levels, index + 1);
}


int main() {
    
    // input
    int N; std::cin >> N;
    std::vector<int> data(N);
    for (int i = 0; i < N; i++)
        std::cin >> data[i];
    // construct tree
    node* tree = constructTree(data, 0, (int)N - 1);
    // create levels and print
    vector<vector<int>> levels;
    constructMap(tree, levels, 0);
    for (size_t i = 0 ; i < levels.size(); i++) {
        for (const int& data : levels[i])
            cout << data << " ";
    }
    return 0;
}
