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
    TreeNode(long long val = 0, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : val(val), left(left), right(right) {}
};

void build_levels(TreeNode* root, std::vector<long long>& minimum, std::vector<long long>& sum, std::size_t index) {
    
    if (!root)
        return;
    
    if (index == sum.size()) {
        sum.push_back(root->val);
        minimum.push_back(root->val);
    } else {
        sum[index] += root->val;
        minimum[index] = std::min(minimum[index], root->val);   
    }
    build_levels(root->left, minimum, sum, index + 1);
    build_levels(root->right, minimum, sum, index + 1);
}

int main() {
    
    // INPUT
    int N; std::cin >> N;
    std::vector<TreeNode*> nodes(N, nullptr);
    for (int i = 0; i < N; i++) {
        int temp; std::cin >> temp;
        nodes[i] = new TreeNode(temp);
    }
    int E; std::cin >> E;
    for (int i = 0; i < E; i++) {
        char dir; int parent, child; std::cin >> dir >> parent >> child;
        if (dir == 'L')
            nodes[parent]->left = nodes[child];
        else
            nodes[parent]->right = nodes[child];
    }
    
    // BUILD LEVELS
    std::vector<long long> minimum;
    std::vector<long long> sum;
    build_levels(nodes[0], minimum, sum, 0);
    
    // OUTPUT
    int L = nodes[0]->val % sum.size();
    int K = minimum[L] % sum.size();
    K = (K == 0) ? 1 : K;
    std::string s = "";
    for (std::size_t i = 0; i < sum.size(); i += K)
        s += std::to_string(sum[i]);
    cout << s;
}
