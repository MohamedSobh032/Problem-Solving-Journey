/*
Given a binary tree determine if there exist two or more subtrees of size bigger than M that have the exact summation and exact size. You are allowed to use unordered_map and unordered_set if needed

Input Format
The first line will contain the number of nodes in the tree N and the size M.
The following N numbers will contain the data in each node.
The next line will contain the number of edges in the tree E.
The following E lines will contain 3 values:
L or R to represent of this is a left or right child
Index of the parent.
Index of the child.

Constraints
N is between 1 and 10^6
Node 0 is always the root
Node values are between 1 and 10^4

Output Format
One line containing 0 if no such subtrees exist and 1 otherwise.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

pair<int, int> adder(node* root, unordered_map<int, unordered_map<int, int>>& nmap, bool& flag, int& M) {
    
    // base-case
    if (!root)
        return {0, 0};
    
    // recursion
    int sum = root->data;
    int size = 1;
    pair<int, int> left = adder(root->left, nmap, flag, M);
    if (flag)
        return {0, 0};
    pair<int, int> right = adder(root->right, nmap, flag, M);
    if (flag)
        return {0, 0};
    sum += left.first + right.first;
    size += left.second + right.second;
    
    if (nmap[sum].find(size) != nmap[sum].end() && size > M) {
        flag = true;
        return {0, 0};
    }
    nmap[sum][size]++;
    return {sum, size};
}

int main() {
    
    int N, M; cin >> N >> M;
    vector<int> values(N);
    for (int i = 0; i < N; i++)
        cin >> values[i];
    int E;
    cin >> E;
    vector<node*> nodes(N);
    for (int i = 0; i < N; i++)
        nodes[i] = new node(values[i]);
    for (int i = 0; i < E; i++) {
        char direction;
        int parent, child;
        cin >> direction >> parent >> child;
        if (direction == 'L')
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    
    unordered_map<int, unordered_map<int, int>> nmap;
    bool flag = false;
    adder(nodes[0], nmap, flag, M);
    cout << (flag ? 1 : 0) << endl;
    return 0;
}
