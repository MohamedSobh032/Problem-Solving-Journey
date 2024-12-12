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

void buildLevels(TreeNode* root, int index, vector<vector<long long>>& levels) {
    
    // base case
    if (!root)
        return;
    if (index == (int)levels.size())
        levels.push_back({});
    
    // add new value
    levels[index].push_back(root->val);
    
    // recursive
    buildLevels(root->left, index + 1, levels);
    buildLevels(root->right, index + 1, levels);
} 

int main() {
    
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
    
    // Build the levels (Each level contains the data of the level from left to right)
    vector<vector<long long>> vect;
    buildLevels(nodes[0], 0, vect);

    // On each level
    for (size_t i = 0; i < vect.size(); i++) {
        // If only 1 item, it is 100% correct
        if (vect[i].size() == 1) {
            cout << 0 << endl;
            continue;
        }
        // Sort the vector, and compare places
        int counter = 0;
        vector<long long> oldVect = vect[i];
        sort(vect[i].begin(), vect[i].end());
        for (size_t j = 0; j < vect[i].size(); j++) {
            if (vect[i][j] != oldVect[j])
                counter++;
        }
        cout << counter << endl;
    }
    return 0;
}