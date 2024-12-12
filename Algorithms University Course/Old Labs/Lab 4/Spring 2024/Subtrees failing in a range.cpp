#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(long long data = 0) : val(data), left(nullptr), right(nullptr) {}
};


bool inRange(TreeNode* root, long long& minimum, long long& maximum, long long& count) {
    
    if (!root)
        return true;
    
    bool acLeft = inRange(root->left, minimum, maximum, count);
    bool acRight = inRange(root->right, minimum, maximum, count);
    
    if (acLeft && acRight && root->val >= minimum && root->val <= maximum) {
        count++;
        return true;
    } else
        return false;
}


int main() {
    
    // INPUT
    long long minimum, maximum;
    std::cin >> minimum;
    std::cin >> maximum;
    long long dataRoot; std::cin >> dataRoot;
    int E; std::cin >> E;
    
    unordered_map<long long, TreeNode*> tree;
    tree[dataRoot] = new TreeNode(dataRoot);
    
    char direction; long long leftData, rightData;
    for (int i = 0; i < E; i++) { 
        std::cin >> direction >> leftData >> rightData;   
        if (tree.find(leftData) == tree.end())
            tree[leftData] = new TreeNode(leftData);
        if (tree.find(rightData) == tree.end())
            tree[rightData] = new TreeNode(rightData);
        
        if (direction == 'L')
            tree[leftData]->left = tree[rightData];
        else
            tree[leftData]->right = tree[rightData];
    }
    
    long long count = 0;
    inRange(tree[dataRoot], minimum, maximum, count);
    cout << count;
    
    return 0;
}
