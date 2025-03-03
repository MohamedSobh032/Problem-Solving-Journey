struct node
{
    node *nodes[26];
    bool marks;
    node() : marks(false)
    {
        for (int i = 0; i < 26; i++)
            nodes[i] = nullptr;
    }
};

class WordDictionary
{
public:
    node *root;
    WordDictionary()
    {
        root = new node();
    }

    void addWord(string word)
    {
        int n = static_cast<int>(word.size());
        node *iterator = root;
        for (int i = 0; i < n; i++)
        {
            int index = static_cast<int>(word[i]) - 97;
            if (iterator->nodes[index] == nullptr)
                iterator->nodes[index] = new node();
            iterator = iterator->nodes[index];
        }
        iterator->marks = true;
    }

    bool search(string word, node *given = nullptr)
    {
        int n = static_cast<int>(word.size());
        node *iterator = (given == nullptr) ? root : given;

        for (int i = 0; i < n; i++)
        {
            if (word[i] == '.')
            {
                for (const auto &node : iterator->nodes)
                    if (node && this->search(word.substr(i + 1), node))
                        return true;
                return false;
            }

            int index = static_cast<int>(word[i]) - 97;
            if (iterator->nodes[index] == nullptr)
                return false;
            iterator = iterator->nodes[index];
        }
        
        return iterator->marks;
    }
};