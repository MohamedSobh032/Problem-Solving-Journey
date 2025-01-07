/**
 * @brief First Solution
 * -- Time Complexity: O(n^2 * m^2)
 * -- Space Complexity: O(n * m)
 * -- Brute-force approach by comparing each word with all other words, until it finds an answer
 */
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        std::vector<std::string> matchers;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && words[j].find(words[i]) != std::string::npos) {
                    matchers.emplace_back(words[i]);
                    break;
                }
            }
        }
        return matchers;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n^2)
 * -- Space Complexity: O(n * m^2)
 * -- Using Trie data structure to store all the words with all prefixes
 *    then check if the word is a substring of any other word
 */
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        std::vector<std::string> matchers;
        TrieNode* root = new TrieNode();

        for (const auto& word: words)
            for (int i = 0; i < word.size(); i++)
                insert_word(root, word.substr(i));

        for (const auto& word: words)
            if (is_substring(root, word))
                matchers.push_back(word);
        
        return matchers;
    }

    class TrieNode {
    public:
        int freq;
        std::unordered_map<char, TrieNode*> children;    
    };

    void insert_word(TrieNode* root, const std::string& word) {

        TrieNode* curr = root;
        for (const auto& c: word) {
            if (curr->children.find(c) != curr->children.end()) {
                curr = curr->children[c];
                curr->freq++;
            } else {
                TrieNode* n = new TrieNode();
                n->freq = 1;
                curr->children[c] = n;
                curr = n;
            }
        }
    }

    bool is_substring(TrieNode* root, const std::string& word) {

        TrieNode* curr = root;
        for (const auto& c: word) curr = curr->children[c];
        return curr->freq > 1;
    }
};

/**
 * @brief Third Solution
 * -- Time Complexity: O(n^2 * m)
 * -- Space Complexity: O(n * m)
 * -- Using KMP algorithm to check if the word is a substring of any other word
 */
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        std::vector<std::string> matchers;
        std::sort(words.begin(), words.end(),
            [](const std::string& a, const std::string& b) {
                return a.size() < b.size();
        });
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (is_substring(words[j], words[i])) {
                    matchers.push_back(words[i]); break;
                }
            }
        }
        return matchers;
    }

    std::vector<int> LPS(const std::string& pattern) {

        int n = pattern.size(); std::vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n; i++) {
            while (len > 0 && pattern[i] != pattern[len]) len = lps[len - 1];
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }

    bool is_substring(const std::string& str, const std::string& pattern) {

        if (pattern.empty()) return true;
        if (str.size() < pattern.size()) return false;

        std::vector<int> lps = LPS(pattern);
        int i = 0, j = 0;

        while (i < str.size()) {
            if (str[i] == pattern[j]) {
                i++; j++;
                if (j == pattern.size()) return true;
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }
};