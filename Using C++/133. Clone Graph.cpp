/**
 * @brief First Solution
 * -- Time Complexity: O(V + E)
 * -- Space Complexity: O(V)
 */
class Solution
{
public:
    Node *dfs(Node *node, std::unordered_map<int, Node *> &isVisited)
    {
        Node *clone = new Node(node->val);
        isVisited[node->val] = clone;
        for (auto &neighbor : node->neighbors)
        {
            if (isVisited.find(neighbor->val) != isVisited.end())
                clone->neighbors.push_back(isVisited[neighbor->val]);
            else
                clone->neighbors.push_back(dfs(neighbor, isVisited));
        }
        return clone;
    }

    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
            
        std::unordered_map<int, Node *> isVisited;
        return dfs(node, isVisited);
    }
};