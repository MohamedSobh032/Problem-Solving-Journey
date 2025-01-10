#include <iostream>
#include <vector>
#include <unordered_map>

struct node {
    int data;
    node* left;
    node* right;
    node(int data = 0) : data(data), left(nullptr), right(nullptr) {}
};

std::pair<int, int> adder(node* root, std::unordered_map<int, std::unordered_map<int, int>>& nmap, bool& flag, int& M) {
    
    // base-case
    if (!root) return {0, 0};
    
    // recursion
    int sum = root->data, size = 1;
    std::pair<int, int> left = adder(root->left, nmap, flag, M);
    if (flag) return {0, 0};
    std::pair<int, int> right = adder(root->right, nmap, flag, M);
    if (flag) return {0, 0};
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
    
    int N, M; std::cin >> N >> M;
    std::vector<int> values(N);
    for (int i = 0; i < N; i++) std::cin >> values[i];
    int E; std::cin >> E;
    std::vector<node*> nodes(N);
    for (int i = 0; i < N; i++) nodes[i] = new node(values[i]);
    for (int i = 0; i < E; i++) {
        char direction; int parent, child;
        std::cin >> direction >> parent >> child;
        if (direction == 'L') nodes[parent]->left = nodes[child];
        else nodes[parent]->right = nodes[child];
    }
    
    std::unordered_map<int, std::unordered_map<int, int>> nmap;
    bool flag = false;
    adder(nodes[0], nmap, flag, M);
    std::cout << flag;
}
