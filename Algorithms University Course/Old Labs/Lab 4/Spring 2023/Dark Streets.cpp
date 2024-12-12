#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    int index;
    TreeNode* parent;
    vector<TreeNode*> child;
    vector<TreeNode*> edges;
    TreeNode(int data = 0) : val(data) {}
};

void func(TreeNode* root, int& counter, int delimiter, const int& M) {
    
    if (!root)
        return;
    if (delimiter > M)
        return;
    if (root->child.size() == 0) {
        if (root->val + delimiter <= M) {
            counter++;
            return;
        } else
            return;
    }
    
    delimiter = root->val == 1 ? delimiter + 1 : 0;
    for (size_t i = 0; i < root->child.size(); i++)
        func(root->child[i], counter, delimiter, M);
}

void getRoot(TreeNode* tree, TreeNode* parent, vector<bool>& isVisited) {
    
    if (!tree) return;
    if (isVisited[tree->index - 1]) return;
    for(size_t i = 0, length = tree->edges.size(); i < length; i++) {
        isVisited[tree->index - 1] = true;
        getRoot(tree->edges[i], tree, isVisited);
    }
    tree->parent = parent;
    if (parent) parent->child.push_back(tree);
}


int main() {
    
    // INPUT
    int M, N; std::cin >> N >> M;
    std::vector<TreeNode*> tree(N);
    for (int i = 0; i < N; i++) {
        int temp = 0; std::cin >> temp;
        tree[i] = new TreeNode(temp);
        tree[i]->index = i + 1;
    }
    
    int E = N - 1;
    for (int i = 0; i < E; i++) {
        int parent, child; std::cin >> parent >> child;
        tree[parent - 1]->edges.push_back(tree[child - 1]);
        tree[child - 1]->edges.push_back(tree[parent - 1]);
    }

    vector<bool> isVisited(N, false);
    TreeNode* root = tree[0];
    
    getRoot(root, nullptr, isVisited);
    
    int counter = 0;
    func(root, counter, 0, M);
    cout << counter;
    
    return 0;
}
