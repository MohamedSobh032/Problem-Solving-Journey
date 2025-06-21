#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
private:
    unordered_map<int, Node *> mp;

public:
    /**
     * @brief DFS (Depth-First Search)
     * @details recursively clones the graph using DFS and a hash map to avoid revisiting nodes
     * @complexity: Time: O(n), Space: O(n) (due to recursion and hashmap)
     */
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        if (mp.find(node->val) != mp.end())
            return mp[node->val];

        Node *n = new Node(node->val);
        mp[node->val] = n;
        if (node->neighbors.size() == 0)
            return mp[node->val];
        for (int i = 0; i < node->neighbors.size(); i++)
            n->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return n;
    }
};