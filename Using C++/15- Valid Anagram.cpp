
/**
 * @brief First Solution
 * -- O(n) 3 times
 * -- Use hashmap to get the total number of usage of each character
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> nmap; 
        for (const char& c : s)
            nmap[c]++;
        for (const char& c : t)
            nmap[c]--;
        for (auto it = nmap.begin(); it != nmap.end(); ++it) {
            if (it->second != 0)
                return false;
        }
        return true;
    }
};

/**
 * @brief Second Solution
 * -- O(n) 3 times
 * -- Same sense of a hashmap, the ideology of knowing where the key is, but with a vector
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int> chars(27, 0);
        for (const char& c : s)
            chars[c - 'a']++;
        for (const char& c : t)
            chars[c - 'a']--;
        for (const int& i : chars) {
            if (i != 0)
                return false;
        }
        return true;
    }
};