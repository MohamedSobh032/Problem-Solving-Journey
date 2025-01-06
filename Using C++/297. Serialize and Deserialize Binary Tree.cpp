/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- For serialization, BFS to traverse the tree and store the values in a string.
 * -- For deserialization, split the string into multiple values and then reconstruct the tree.
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        
        if (!root) return "";

        std::string ser("");
        std:queue<TreeNode*> q; q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            ser.append((node ? std::to_string(node->val) : "null")); ser.append(",");
            if (!node) continue;
            q.push(node->left); q.push(node->right);
        }
        return ser;
    }

    TreeNode* deserialize(string data) {

        // sanity check        
        if (data == "") return nullptr;

        // divide into multiple values
        std::vector<TreeNode*> nodes;
        std::stringstream ss(data);
        std::string token;
        while (std::getline(ss, token, ',')) {
            if (token == "null") nodes.push_back(nullptr);
            else nodes.push_back(new TreeNode(std::stoi(token)));
        }
        
        // deserialization
        int n = nodes.size(), next_to_point = 1;
        for (int i = 0; i < n; i++) {
            if (!nodes[i]) continue;
            nodes[i]->left = (next_to_point < n) ? nodes[next_to_point] : nullptr; next_to_point++;
            nodes[i]->right = (next_to_point< n) ? nodes[next_to_point] : nullptr; next_to_point++;
        }
        return nodes[0];
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(n)
 * -- For serialization, DFS to traverse the tree and appends the value in the string
 * -- For deserialization, split the string into multiple values and then reconstruct the tree by DFS.
 */
class Codec {
public:

    void serialize_dfs(TreeNode* root, std::string& stream) {
        
        if (!root) { stream.append("null"); stream.append(","); return; }
        stream.append(std::to_string(root->val)); stream.append(",");
        serialize_dfs(root->left, stream);
        serialize_dfs(root->right, stream);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        std::string result(""); serialize_dfs(root, result);
        // Remove the last comma
        if (!result.empty()) result.pop_back();
        return result;
    }

    TreeNode* deserialize_dfs(std::queue<std::string>& nodes) {
        
        std::string val(nodes.front()); nodes.pop();
        if (val == "null") return nullptr;
        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserialize_dfs(nodes);
        node->right = deserialize_dfs(nodes);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        std::queue<std::string> nodes;
        std::stringstream ss(data);
        std::string item;
        while (getline(ss, item, ',')) nodes.push(item);
        return deserialize_dfs(nodes);
    }
};