struct node {
    node* nodes[26];
    bool marks;
    node(): marks(false) {
        for (int i = 0; i < 26; i++)
            nodes[i] = nullptr;
    }
};

class Trie {
public:
    node* root;
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        
        int n = static_cast<int>(word.size());
        node* iterator = root;
        for (int i = 0; i < n; i++) {
            int index = static_cast<int>(word[i]) - 97;
            if (iterator->nodes[index] == nullptr)
                iterator->nodes[index] = new node();
            iterator = iterator->nodes[index];
        }
        iterator->marks = true;
    }
    
    bool search(string word) {
        
        int n = static_cast<int>(word.size());
        node* iterator = root;
        for (int i = 0; i < n; i++) {
            int index = static_cast<int>(word[i]) - 97;
            if (iterator->nodes[index] == nullptr)
                return false;
            iterator = iterator->nodes[index];
        }
        return iterator->marks;
    }
    
    bool startsWith(string prefix) {
        
        int n = static_cast<int>(prefix.size());
        node* iterator = root;
        for (int i = 0; i < n; i++) {
            int index = static_cast<int>(prefix[i]) - 97;
            if (iterator->nodes[index] == nullptr)
                return false;
            iterator = iterator->nodes[index];
        }
        return true;
    }
};